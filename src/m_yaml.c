#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "m_yaml.h"

void yaml_iter_init(yaml_iter_t *iter, yaml_document_t *document)
{
    assert(iter);
    assert(document);

    memset(iter, 0, sizeof(yaml_iter_t));

    iter->document = document;
    iter->node = yaml_document_get_root_node(document);

    assert(iter->node);
    if (iter->node->type == YAML_MAPPING_NODE)
        iter->pair = iter->node->data.mapping.pairs.start - 1;
    else if (iter->node->type == YAML_SEQUENCE_NODE)
        iter->item = iter->node->data.sequence.items.start - 1;
}

int yaml_iter_next(yaml_iter_t *iter)
{
    assert(iter);
    assert(iter->document);
    assert(iter->node);

    if (iter->node->type == YAML_MAPPING_NODE)
    {
        if (iter->pair)
        {
            iter->pair++;
            if (iter->pair < iter->node->data.mapping.pairs.top)
                return 1;
        }

    }
    else if (iter->node->type == YAML_SEQUENCE_NODE)
    {
        if (iter->item)
        {
            iter->item++;
            if (iter->item < iter->node->data.sequence.items.top)
                return 1;
        }
    }

    return 0;
}

void yaml_iter_recurse(yaml_iter_t *parent, yaml_iter_t *iter)
{
    assert(parent);
    assert(parent->document);
    assert(parent->node);
    assert(iter);

    memset(iter, 0, sizeof(yaml_iter_t));

    iter->document = parent->document;

    if (parent->node->type == YAML_MAPPING_NODE)
    {
        assert(parent->pair);
        iter->node = yaml_document_get_node(
                parent->document, parent->pair->value);
        assert(iter->node);
        if (iter->node->type == YAML_MAPPING_NODE)
            iter->pair = iter->node->data.mapping.pairs.start - 1;
        else if (iter->node->type == YAML_SEQUENCE_NODE)
            iter->item = iter->node->data.sequence.items.start - 1;
    }
    else if (parent->node->type == YAML_SEQUENCE_NODE)
    {
        assert(parent->item);
        iter->node = yaml_document_get_node(parent->document, *parent->item);
        assert(iter->node);
        if (iter->node->type == YAML_MAPPING_NODE)
            iter->pair = iter->node->data.mapping.pairs.start - 1;
        else if (iter->node->type == YAML_SEQUENCE_NODE)
            iter->item = iter->node->data.sequence.items.start - 1;
    }
    else
        abort();
}

int yaml_iter_type(yaml_iter_t *iter)
{
    assert(iter);
    assert(iter->node);

    return iter->node->type;
}


const char *yaml_iter_key(yaml_iter_t *iter)
{
    yaml_node_t *node = NULL;

    assert(iter);
    assert(iter->document);
    assert(iter->node);

    if (iter->node->type == YAML_MAPPING_NODE)
    {
        assert(iter->pair);
        node = yaml_document_get_node(iter->document, iter->pair->key);
        assert(node);
        assert(node->type == YAML_SCALAR_NODE);

        return (const char *)node->data.scalar.value;
    }
    else if (iter->node->type == YAML_SEQUENCE_NODE)
    {
        assert(iter->item);
        node = yaml_document_get_node(iter->document, *iter->item);
        assert(node);
        assert(node->type == YAML_SCALAR_NODE);

        return (const char *)node->data.scalar.value;
    }

    abort();
    return NULL;
}

const char *yaml_iter_value(yaml_iter_t *iter)
{
    assert(iter);
    assert(iter->document);
    assert(iter->node);

    if (iter->node->type == YAML_SCALAR_NODE)
    {
        return (const char *)iter->node->data.scalar.value;
    }
    else if (iter->node->type == YAML_MAPPING_NODE)
    {
        yaml_node_t *node = NULL;

        assert(iter->pair);
        node = yaml_document_get_node(iter->document, iter->pair->value);
        assert(node);
        assert(node->type == YAML_SCALAR_NODE);

        return (const char *)node->data.scalar.value;
    }
    else if (iter->node->type == YAML_SEQUENCE_NODE)
    {
        yaml_node_t *node = NULL;

        assert(iter->item);
        node = yaml_document_get_node(iter->document, *iter->item);
        assert(node);
        assert(node->type == YAML_SCALAR_NODE);

        return (const char *)node->data.scalar.value;
    }

    abort();
    return NULL;
}

int yaml_iter_has_value(yaml_iter_t *iter)
{
    assert(iter);
    assert(iter->document);
    assert(iter->node);

    if (iter->node->type == YAML_SCALAR_NODE) {
        return 1;
    } else if (iter->node->type == YAML_MAPPING_NODE) {
        yaml_node_t *node = NULL;

        assert(iter->pair);
        node = yaml_document_get_node(iter->document, iter->pair->value);
        assert(node);
        return node->type == YAML_SCALAR_NODE;
    } else if (iter->node->type == YAML_SEQUENCE_NODE) {
        yaml_node_t *node = NULL;

        assert(iter->item);
        node = yaml_document_get_node(iter->document, *iter->item);
        assert(node);
        return node->type == YAML_SCALAR_NODE;
    }

    abort();
    return 0;
}

int yaml_iter_bool(yaml_iter_t *iter)
{
    const char *v = yaml_iter_value(iter);
    if (v)
    {
        if (!strcasecmp(v, "true") || !strcasecmp(v, "yes")) return 1;
        if (atoi(v)) return 1;
    }

    return 0;
}
