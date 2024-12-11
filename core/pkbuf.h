#ifndef _PKBUF_H
#define _PKBUF_H

// #define __USE_MISC
#include "list.h"
#include "mempool.h"
#include <stdint.h>
#include <string.h>
#include <endian.h>

#define TO_STRING(n) #n

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cluster_s
{
    unsigned char *buffer;
    unsigned int size;

    unsigned int reference_count;
}cluster_t;

typedef struct pkbuf_pool_s pkbuf_pool_t;
typedef struct pkbuf_s 
{
    struct list lnode;

    /* Currently it is used in SCTP stream number and PPID. */
    uint64_t param[2];

    cluster_t *cluster;

    unsigned int len;

    unsigned char *head;
    unsigned char *tail;
    unsigned char *data;
    unsigned char *end;

    const char *file_line;
    
    pkbuf_pool_t *pool;

    unsigned char _data[0]; /*!< optional immediate data array */
}pkbuf_t;

typedef struct pkbuf_config_s
{
    int cluster_128_pool;
    int cluster_256_pool;
    int cluster_512_pool;
    int cluster_1024_pool;
    int cluster_2048_pool;
    int cluster_8192_pool;
    int cluster_32768_pool;
    int cluster_big_pool;
}pkbuf_config_t;

void pkbuf_init(void);
void pkbuf_final(void);

void pkbuf_default_init(pkbuf_config_t* config);
void pkbuf_default_create(pkbuf_config_t* config);
void pkbuf_default_destroy(void);

pkbuf_pool_t* pkbuf_pool_create(pkbuf_config_t* config);
void pkbuf_pool_destroy(pkbuf_pool_t* pool);

#define pkbuf_alloc(pool, size) \
    pkbuf_alloc_debug(pool, size, __FILE__ ":" TO_STRING(__LINE__))
pkbuf_t* pkbuf_alloc_debug(
        pkbuf_pool_t *pool, unsigned int size, const char* file_line);
void pkbuf_free(pkbuf_t *pkbuf);

void* pkbuf_put_data(
        pkbuf_t *pkbuf, const void *data, unsigned int len);
#define pkbuf_copy(pkbuf) \
    pkbuf_copy_debug(pkbuf, OGS_FILE_LINE)
pkbuf_t* pkbuf_copy_debug(pkbuf_t* pkbuf, const char* file_line);

static inline int pkbuf_tailroom(const pkbuf_t *pkbuf)
{
    return pkbuf->end - pkbuf->tail;
}

static inline int pkbuf_headroom(const pkbuf_t *pkbuf)
{
    return pkbuf->data - pkbuf->head;
}

static inline void pkbuf_reserve(pkbuf_t *pkbuf, int len)
{
    pkbuf->data += len;
    pkbuf->tail += len;
}

static inline void *pkbuf_put(pkbuf_t *pkbuf, unsigned int len)
{
    void *tmp = pkbuf->tail;

    if (pkbuf_tailroom(pkbuf) < (int)len)
        abort();

    pkbuf->tail += len;
    pkbuf->len += len;

    return tmp;
}

static inline void pkbuf_put_u8(pkbuf_t *pkbuf, uint8_t val)
{
    *(uint8_t *)pkbuf_put(pkbuf, 1) = val;
}

static inline void pkbuf_put_u16(pkbuf_t *pkbuf, uint16_t val)
{
    void *p = pkbuf_put(pkbuf, 2);
    uint16_t tmp = htobe16(val);
    memcpy(p, &tmp, 2);
}

static inline void pkbuf_put_u32(pkbuf_t *pkbuf, uint32_t val)
{
    void *p = pkbuf_put(pkbuf, 4);
    uint32_t tmp = htobe32(val);
    memcpy(p, &tmp, 4);
}

static inline void *pkbuf_push(pkbuf_t *pkbuf, unsigned int len)
{
    if (pkbuf_headroom(pkbuf) < (int)len)
        abort();

    pkbuf->data -= len;
    pkbuf->len += len;

    return pkbuf->data;
}

static inline void *pkbuf_pull_inline(
        pkbuf_t *pkbuf, unsigned int len)
{
    pkbuf->len -= len;
    return pkbuf->data += len;
}

static inline void *pkbuf_pull(pkbuf_t *pkbuf, unsigned int len)
{
    return len > pkbuf->len ?
        NULL : pkbuf_pull_inline(pkbuf, len);
}

static inline int pkbuf_trim(pkbuf_t *pkbuf, int len)
{
    if (len < 0)
        abort();
    if (len > pkbuf->len) 
    {
        // ogs_error("len(%d) > pkbuf->len(%d)", len, pkbuf->len);
        return -1;
    }

    pkbuf->tail = pkbuf->data + len;
    pkbuf->len = len;

    return 0;
}

#ifdef __cplusplus
}
#endif

#endif /* OGS_PKBUF_H */
