#ifndef _M_YAML_H
#define _M_YAML_H

#include <yaml.h>

#ifdef __cplusplus
extern "C" {
#endif

#define YAML_ARRAY_RECURSE(ARRAY, ITERATOR) \
    if (yaml_iter_type(ARRAY) == YAML_MAPPING_NODE) { \
        memcpy((ITERATOR), (ARRAY), sizeof(yaml_iter_t)); \
    } else if (yaml_iter_type(ARRAY) == YAML_SEQUENCE_NODE) { \
        yaml_iter_recurse((ARRAY), (ITERATOR)); \
    } else if (yaml_iter_type(ARRAY) == YAML_SCALAR_NODE) { \
        break; \
    } else \
        abort();

#define OGS_YAML_ARRAY_NEXT(ARRAY, ITERATOR) \
    if (yaml_iter_type(ARRAY) == YAML_SEQUENCE_NODE && \
        !yaml_iter_next(ARRAY)) break; \
    YAML_ARRAY_RECURSE(ARRAY, ITERATOR);

typedef struct {
    yaml_document_t *document;
    yaml_node_t *node;
    yaml_node_pair_t *pair;
    yaml_node_item_t *item;
} yaml_iter_t;

void yaml_iter_init(yaml_iter_t *iter, yaml_document_t *document);
int yaml_iter_next(yaml_iter_t *iter);
void yaml_iter_recurse(yaml_iter_t *parent, yaml_iter_t *iter);

int yaml_iter_type(yaml_iter_t *iter);
const char *yaml_iter_key(yaml_iter_t *iter);
const char *yaml_iter_value(yaml_iter_t *iter);
int yaml_iter_has_value(yaml_iter_t *iter);
int yaml_iter_bool(yaml_iter_t *iter);

#ifdef __cplusplus
}
#endif
#endif