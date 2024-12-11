#include "pkbuf.h"
#include "mempool.h"
#include <pthread.h>

#define CLUSTER_128_SIZE    128
#define CLUSTER_256_SIZE    256
#define CLUSTER_512_SIZE    512
#define CLUSTER_1024_SIZE   1024
#define CLUSTER_2048_SIZE   2048
#define CLUSTER_8192_SIZE   8192
#define CLUSTER_32768_SIZE  32768
#define CLUSTER_BIG_SIZE    (1024 * 1024 + sizeof(pkbuf_t *))

typedef uint8_t cluster_128_t[CLUSTER_128_SIZE];
typedef uint8_t cluster_256_t[CLUSTER_256_SIZE];
typedef uint8_t cluster_512_t[CLUSTER_512_SIZE];
typedef uint8_t cluster_1024_t[CLUSTER_1024_SIZE];
typedef uint8_t cluster_2048_t[CLUSTER_2048_SIZE];
typedef uint8_t cluster_8192_t[CLUSTER_8192_SIZE];
typedef uint8_t cluster_32768_t[CLUSTER_32768_SIZE];
typedef uint8_t cluster_big_t[CLUSTER_BIG_SIZE];

typedef struct pkbuf_pool_s {
    MEM_POOL(pkbuf, pkbuf_t);
    MEM_POOL(cluster, cluster_t);

    MEM_POOL(cluster_128, cluster_128_t);
    MEM_POOL(cluster_256, cluster_256_t);
    MEM_POOL(cluster_512, cluster_512_t);
    MEM_POOL(cluster_1024, cluster_1024_t);
    MEM_POOL(cluster_2048, cluster_2048_t);
    MEM_POOL(cluster_8192, cluster_8192_t);
    MEM_POOL(cluster_32768, cluster_32768_t);
    MEM_POOL(cluster_big, cluster_big_t);
}pkbuf_pool_t;

static MEM_POOL(pkbuf_pool, pkbuf_pool_t);
static pkbuf_pool_t *default_pool = NULL;

static cluster_t *cluster_alloc(
        pkbuf_pool_t *pool, unsigned int size);
static void cluster_free(pkbuf_pool_t *pool, cluster_t *cluster);

void* pkbuf_put_data(
        pkbuf_t *pkbuf, const void *data, unsigned int len)
{
    void *tmp = pkbuf_put(pkbuf, len);

    memcpy(tmp, data, len);
    return tmp;
}

void pkbuf_init(void)
{
    mempool_init(&pkbuf_pool, 4);
}

void pkbuf_final(void)
{
    mempool_destroy(&pkbuf_pool);
}

void pkbuf_default_init(pkbuf_config_t *config)
{
    assert(config);
    memset(config, 0, sizeof *config);

    config->cluster_128_pool = 65536;
    config->cluster_256_pool = 16384;
    config->cluster_512_pool = 4096;
    config->cluster_1024_pool = 2048;
    config->cluster_2048_pool = 1024;
    config->cluster_8192_pool = 256;
    config->cluster_32768_pool = 64;
    config->cluster_big_pool = 8;
}

void pkbuf_default_create(pkbuf_config_t *config)
{
    default_pool = pkbuf_pool_create(config);
}

void pkbuf_default_destroy(void)
{
    pkbuf_pool_destroy(default_pool);
}

pkbuf_pool_t* pkbuf_pool_create(pkbuf_config_t *config)
{
    pkbuf_pool_t *pool = NULL;

    int tmp = 0;

    assert(config);

    mempool_alloc(&pkbuf_pool, &pool);
    assert(pool);
    memset(pool, 0, sizeof *pool);

    //ogs_thread_mutex_init(&pool->mutex);

    tmp = config->cluster_128_pool + config->cluster_256_pool +
        config->cluster_512_pool + config->cluster_1024_pool +
        config->cluster_2048_pool + config->cluster_8192_pool +
        config->cluster_32768_pool + config->cluster_big_pool;

    mempool_init(&pool->pkbuf, tmp);
    mempool_init(&pool->cluster, tmp);

    mempool_init(&pool->cluster_128, config->cluster_128_pool);
    mempool_init(&pool->cluster_256, config->cluster_256_pool);
    mempool_init(&pool->cluster_512, config->cluster_512_pool);
    mempool_init(&pool->cluster_1024, config->cluster_1024_pool);
    mempool_init(&pool->cluster_2048, config->cluster_2048_pool);
    mempool_init(&pool->cluster_8192, config->cluster_8192_pool);
    mempool_init(&pool->cluster_32768, config->cluster_32768_pool);
    mempool_init(&pool->cluster_big, config->cluster_big_pool);

    return pool;
}

#define pkbuf_pool_final(pool) do { \
    if (((pool)->size != (pool)->avail)) { \
        int i; \
        fprintf(stderr, "%d in '%s[%d]' were not released.", \
                (pool)->size - (pool)->avail, (pool)->name, (pool)->size); \
        for (i = 0; i < (pool)->size; i++) { \
            pkbuf_t *pkbuf = (pool)->index[i]; \
            if (pkbuf) { \
                fprintf(stderr, "SIZE[%d] is not freed. (%s)\n", \
                        pkbuf->len, pkbuf->file_line); \
            } \
        } \
    } \
    free((pool)->free); \
    free((pool)->array); \
    free((pool)->index); \
} while (0)

void pkbuf_pool_destroy(pkbuf_pool_t *pool)
{
    assert(pool);

    pkbuf_pool_final(&pool->pkbuf);
    mempool_destroy(&pool->cluster);

    mempool_destroy(&pool->cluster_128);
    mempool_destroy(&pool->cluster_256);
    mempool_destroy(&pool->cluster_512);
    mempool_destroy(&pool->cluster_1024);
    mempool_destroy(&pool->cluster_2048);
    mempool_destroy(&pool->cluster_8192);
    mempool_destroy(&pool->cluster_32768);
    mempool_destroy(&pool->cluster_big);

    // ogs_thread_mutex_destroy(&pool->mutex);

    mempool_free(&pkbuf_pool, pool);
}

pkbuf_t* pkbuf_alloc_debug(
        pkbuf_pool_t *pool, unsigned int size, const char *file_line)
{
    pkbuf_t *pkbuf = NULL;
    cluster_t *cluster = NULL;

    if (pool == NULL)
        pool = default_pool;
    assert(pool);

    // ogs_thread_mutex_lock(&pool->mutex);

    cluster = cluster_alloc(pool, size);
    if (!cluster) {
        // ogs_error("ogs_pkbuf_alloc() failed [size=%d]", size);
        // ogs_thread_mutex_unlock(&pool->mutex);
        return NULL;
    }

    mempool_alloc(&pool->pkbuf, &pkbuf);
    if (!pkbuf) {
        // ogs_error("ogs_pkbuf_alloc() failed [size=%d]", size);
        // ogs_thread_mutex_unlock(&pool->mutex);
        return NULL;
    }
    memset(pkbuf, 0, sizeof(*pkbuf));

    cluster->reference_count++;

    pkbuf->cluster = cluster;

    pkbuf->len = 0;

    pkbuf->data = cluster->buffer;
    pkbuf->head = cluster->buffer;
    pkbuf->tail = cluster->buffer;
    pkbuf->end = cluster->buffer + size;

    pkbuf->file_line = file_line; /* For debug */

    pkbuf->pool = pool;

    // ogs_thread_mutex_unlock(&pool->mutex);

    return pkbuf;
}

void pkbuf_free(pkbuf_t *pkbuf)
{
    pkbuf_pool_t *pool = NULL;
    cluster_t *cluster = NULL;
    assert(pkbuf);

    pool = pkbuf->pool;
    assert(pool);

    // ogs_thread_mutex_lock(&pool->mutex);

    cluster = pkbuf->cluster;
    assert(cluster);

    if (cluster->reference_count > 1)
        cluster->reference_count--;
    else
        cluster_free(pool, pkbuf->cluster);

    mempool_free(&pool->pkbuf, pkbuf);

    // ogs_thread_mutex_unlock(&pool->mutex);

}

pkbuf_t* pkbuf_copy_debug(pkbuf_t *pkbuf, const char *file_line)
{
    pkbuf_pool_t *pool = NULL;
    pkbuf_t *newbuf = NULL;
    int size = 0;

    assert(pkbuf);
    size = pkbuf->end - pkbuf->head;
    if (size <= 0) {
        // ogs_error("Invalid argument[size=%d, head=%p, end=%p] in (%s)",
        //         size, pkbuf->head, pkbuf->end, file_line);
        return NULL;
    }

    pool = pkbuf->pool;
    assert(pool);

    // ogs_thread_mutex_lock(&pool->mutex);

    mempool_alloc(&pool->pkbuf, &newbuf);
    if (!newbuf) {
        // ogs_error("ogs_pkbuf_copy() failed [size=%d]", size);
        // ogs_thread_mutex_unlock(&pool->mutex);
        return NULL;
    }
    assert(newbuf);
    memcpy(newbuf, pkbuf, sizeof *pkbuf);

    newbuf->cluster->reference_count++;

    // ogs_thread_mutex_unlock(&pool->mutex);

    return newbuf;
}

static cluster_t *cluster_alloc(
        pkbuf_pool_t *pool, unsigned int size)
{
    cluster_t *cluster = NULL;
    void *buffer = NULL;
    assert(pool);

    mempool_alloc(&pool->cluster, &cluster);
    assert(cluster);
    memset(cluster, 0, sizeof(*cluster));

    if (size <= CLUSTER_128_SIZE) {
        mempool_alloc(&pool->cluster_128, (cluster_128_t**)&buffer);
        if (!buffer) {
            // ogs_error("ogs_pool_alloc() failed");
            return NULL;
        }
        cluster->size = CLUSTER_128_SIZE;
    } else if (size <= CLUSTER_256_SIZE) {
        mempool_alloc(&pool->cluster_256, (cluster_256_t**)&buffer);
        if (!buffer) {
            // ogs_error("ogs_pool_alloc() failed");
            return NULL;
        }
        cluster->size = CLUSTER_256_SIZE;
    } else if (size <= CLUSTER_512_SIZE) {
        mempool_alloc(&pool->cluster_512, (cluster_512_t**)&buffer);
        if (!buffer) {
            // ogs_error("ogs_pool_alloc() failed");
            return NULL;
        }
        cluster->size = CLUSTER_512_SIZE;
    } else if (size <= CLUSTER_1024_SIZE) {
        mempool_alloc(&pool->cluster_1024, (cluster_1024_t**)&buffer);
        if (!buffer) {
            // ogs_error("ogs_pool_alloc() failed");
            return NULL;
        }
        cluster->size = CLUSTER_1024_SIZE;
    } else if (size <= CLUSTER_2048_SIZE) {
        mempool_alloc(&pool->cluster_2048, (cluster_2048_t**)&buffer);
        if (!buffer) {
            // ogs_error("ogs_pool_alloc() failed");
            return NULL;
        }
        cluster->size = CLUSTER_2048_SIZE;
    } else if (size <= CLUSTER_8192_SIZE) {
        mempool_alloc(&pool->cluster_8192, (cluster_8192_t**)&buffer);
        if (!buffer) {
            // ogs_error("ogs_pool_alloc() failed");
            return NULL;
        }
        cluster->size = CLUSTER_8192_SIZE;
    } else if (size <= CLUSTER_32768_SIZE) {
        mempool_alloc(&pool->cluster_32768, (cluster_32768_t**)&buffer);
        if (!buffer) {
            // ogs_error("ogs_pool_alloc() failed");
            return NULL;
        }
        cluster->size = CLUSTER_32768_SIZE;
    } else if (size <= CLUSTER_BIG_SIZE) {
        mempool_alloc(&pool->cluster_big, (cluster_big_t**)&buffer);
        if (!buffer) {
            // ogs_error("ogs_pool_alloc() failed");
            return NULL;
        }
        cluster->size = CLUSTER_BIG_SIZE;
    } else {
        // ogs_fatal("invalid size = %d", size);
        // ogs_assert_if_reached();
    }
    cluster->buffer = buffer;

    return cluster;
}

static void cluster_free(pkbuf_pool_t *pool, cluster_t *cluster)
{
    assert(pool);
    assert(cluster);
    assert(cluster->buffer);

    switch (cluster->size) {
    case CLUSTER_128_SIZE:
        mempool_free(&pool->cluster_128, (cluster_128_t*)cluster->buffer);
        break;
    case CLUSTER_256_SIZE:
        mempool_free(&pool->cluster_256, (cluster_256_t*)cluster->buffer);
        break;
    case CLUSTER_512_SIZE:
        mempool_free(&pool->cluster_512, (cluster_512_t*)cluster->buffer);
        break;
    case CLUSTER_1024_SIZE:
        mempool_free(
                &pool->cluster_1024, (cluster_1024_t*)cluster->buffer);
        break;
    case CLUSTER_2048_SIZE:
        mempool_free(
                &pool->cluster_2048, (cluster_2048_t*)cluster->buffer);
        break;
    case CLUSTER_8192_SIZE:
        mempool_free(
                &pool->cluster_8192, (cluster_8192_t*)cluster->buffer);
        break;
    case CLUSTER_32768_SIZE:
        mempool_free(
                &pool->cluster_32768, (cluster_32768_t*)cluster->buffer);
        break;
    case CLUSTER_BIG_SIZE:
        mempool_free(&pool->cluster_big, (cluster_big_t*)cluster->buffer);
        break;
    default:
        break;
    }

    mempool_free(&pool->cluster, cluster);
}

