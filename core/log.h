#ifndef _LOG_H
#define _LOG_H 

#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include "list.h"
#include "mempool.h"

#define LOG_DOMAIN  1

typedef enum {
    LOG_NONE,
    LOG_FATAL,
    LOG_ERROR,
    LOG_WARN,
    LOG_INFO,
    LOG_DEBUG,
    LOG_TRACE,
    LOG_DEFAULT = LOG_INFO,
    LOG_FULL = LOG_TRACE,
}log_level_e;

typedef enum {
    LOG_TS_UNSET,
    LOG_TS_ENABLED,
    LOG_TS_DISABLED,
}log_ts_e;

#define log_fatal(...) log_message(LOG_FATAL, 0, __VA_ARGS__)
#define log_error(...) log_message(LOG_ERROR, 0, __VA_ARGS__)
#define log_warn(...) log_message(LOG_WARN, 0, __VA_ARGS__)
#define log_info(...) log_message(LOG_INFO, 0, __VA_ARGS__)
#define log_debug(...) log_message(LOG_DEBUG, 0, __VA_ARGS__)

#define log_message(level, err, ...) \
    log_printf(level, LOG_DOMAIN, \
    err, __FILE__, __LINE__, __func__, \
    0, __VA_ARGS__)

#define log_print(level, ...) \
    log_printf(level, LOG_DOMAIN, \
    0, NULL, 0, NULL,  \
    1, __VA_ARGS__) 

#define log_hexdump(level, _d, _l) \
    log_hexdump_func(level, LOG_DOMAIN, _d, _l)

typedef struct log_s log_t;
typedef struct log_domain_s log_domain_t;

void log_init(void);
void log_final(void);
void log_cycle(void);

log_t* log_add_stderr(void);
log_t* log_add_file(const char* name);
void log_remove(log_t* log);

log_domain_t *log_add_domain(const char *name, log_level_e level);
log_domain_t *log_find_domain(const char *name);
void log_remove_domain(log_domain_t *domain);

void log_set_domain_level(int id, log_level_e level);
log_level_e log_get_domain_level(int id);

const char *log_get_domain_name(int id);
int log_get_domain_id(const char *name);

void log_install_domain(int *domain_id,
        const char *name, log_level_e level);
int log_config_domain(const char *domain, const char *level);

void log_set_mask_level(const char *mask, log_level_e level);
void log_set_timestamp(log_ts_e ts_default, log_ts_e ts_file);

void log_vprintf(log_level_e level, int id,
    int err, const char *file, int line, const char *func,
    int content_only, const char *format, va_list ap);
void log_printf(log_level_e level, int domain_id,
    int err, const char *file, int line, const char *func,
    int content_only, const char *format, ...);

void log_hexdump_func(log_level_e level, int domain_id,
    const unsigned char *data, size_t len);

///
int log_vsnprintf(char *str, size_t size, const char *format, va_list ap);

int log_snprintf(char *str, size_t size, const char *format, ...);

char* log_vslprintf(char *str, char *last, const char *format, va_list ap);

char* log_slprintf(char *str, char *last, const char *format, ...);

#define log_assert(expr) \
    do { \
        if (expr) ; \
        else { \
            log_fatal("%s: Assertion `%s' failed.", __func__, #expr); \
            abort(); \
        } \
    } while(0)

#define log_assert_if_reached() \
    do { \
        log_fatal("%s: should not be reached.", __func__); \
        abort(); \
    } while(0)

#define log_expect(expr) \
    do { \
        if (expr) ; \
        else { \
            log_error("%s: Expectation `%s' failed.", __func__, #expr); \
        } \
    } while (0)

#ifdef __cplusplus
}
#endif

#endif
