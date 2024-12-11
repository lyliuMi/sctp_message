#ifndef _MEMPOOL_H
#define _MEMPOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MEM_POOL(pool, type) \
    struct { \
        const char* name; \
        int head, tail; \
        int size, avail; \
        type** free, *array, **index;\
    }pool

/*
 * ogs_pool_init() shall be used in the initialization routine.
 * Otherwise, memory will be fragment since this function uses system malloc()
 */
#define mempool_init(pool, _size) do { \
    int i; \
    (pool)->name = #pool; \
    (pool)->free = malloc(sizeof(*(pool)->free) * _size); \
    assert((pool)->free); \
    (pool)->array = malloc(sizeof(*(pool)->array) * _size); \
    assert((pool)->array); \
    (pool)->index = malloc(sizeof(*(pool)->index) * _size); \
    assert((pool)->index); \
    (pool)->size = (pool)->avail = _size; \
    (pool)->head = (pool)->tail = 0; \
    for (i = 0; i < _size; i++) { \
        (pool)->free[i] = &((pool)->array[i]); \
        (pool)->index[i] = NULL; \
    } \
} while (0)

#define mempool_alloc(pool, node) do { \
    *(node) = NULL; \
    if ((pool)->avail > 0) { \
        (pool)->avail--; \
        *(node) = (void*)(pool)->free[(pool)->head]; \
        (pool)->free[(pool)->head] = NULL; \
        (pool)->head = ((pool)->head + 1) % ((pool)->size); \
        (pool)->index[mempool_index(pool, *(node))-1] = *(node); \
    } \
} while (0)

#define mempool_free(pool, node) do { \
    if ((pool)->avail < (pool)->size) { \
        (pool)->avail++; \
        (pool)->free[(pool)->tail] = (void*)(node); \
        (pool)->tail = ((pool)->tail + 1) % ((pool)->size); \
        (pool)->index[mempool_index(pool, node)-1] = NULL; \
    } \
} while (0)


/*
 * ogs_pool_final() shall be used in the finalization routine.
 * Otherwise, memory will be fragment since this function uses system free()
 */
#define mempool_destroy(pool) do { \
    if (((pool)->size != (pool)->avail)) \
        fprintf(stderr, "%d in '%s[%d]' were not released.", \
                (pool)->size - (pool)->avail, (pool)->name, (pool)->size); \
    free((pool)->free); \
    free((pool)->array); \
    free((pool)->index); \
} while (0)

#define mempool_index(pool, node) (((node) - (pool)->array)+1)
#define mempool_find(pool, _index) \
    (_index > 0 && _index <= (pool)->size) ? (pool)->index[_index-1] : NULL

#ifdef __cplusplus
}
#endif

#endif