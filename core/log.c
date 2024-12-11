#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "log.h"

#define TA_NOR              "\033[0m"       /* all off */

#define TA_FGC_BLACK        "\033[30m"      /* Black */
#define TA_FGC_RED          "\033[31m"      /* Red */
#define TA_FGC_BOLD_RED     "\033[1;31m"    /* Bold Red */
#define TA_FGC_GREEN        "\033[32m"      /* Green */
#define TA_FGC_BOLD_GREEN   "\033[1;32m"    /* Bold Green */
#define TA_FGC_YELLOW       "\033[33m"      /* Yellow */
#define TA_FGC_BOLD_YELLOW  "\033[1;33m"    /* Bold Yellow */
#define TA_FGC_BOLD_BLUE    "\033[1;34m"    /* Bold Blue */
#define TA_FGC_BOLD_MAGENTA "\033[1;35m"    /* Bold Magenta */
#define TA_FGC_BOLD_CYAN    "\033[1;36m"    /* Bold Cyan */
#define TA_FGC_WHITE        "\033[37m"      /* White  */
#define TA_FGC_BOLD_WHITE   "\033[1;37m"    /* Bold White  */
#define TA_FGC_DEFAULT      "\033[39m"      /* default */

const char* level_strings[] = 
{
    NULL,
    "FATAL", "ERROR", "WARNING", "INFO", "DEBUG", "TRACE",
};

typedef enum 
{
    LOG_STDERR_TYPE,
    LOG_FILE_TYPE,
}log_type_e;

static struct list log_t_list;
static struct list log_domain_list;
static MEM_POOL(log_pool, log_t);
static MEM_POOL(domain_pool, log_domain_t);

typedef struct log_s
{
    struct list node;
    log_type_e type;

    struct 
    {
        FILE* out;
        const char* name;
    }file;
    struct 
    {
        uint8_t color:1;
        uint8_t timestamp:1;
        uint8_t domain:1;
        uint8_t level:1;
        uint8_t fileline:1;
        uint8_t function:1;
        uint8_t linefeed:1;
    }print;
    
    void (*writer)(log_t *log, log_level_e level, const char *string);
}log_t;

typedef struct log_domain_s 
{
    struct list node;
    int id;
    log_level_e level;
    const char *name;
}log_domain_t;

static log_t* add_log(log_type_e type);
static int file_cycle(log_t *log);

static char* log_timestamp(char *buf, char *last,
        int use_color);
static char* log_domain(char *buf, char *last,
        const char *name, int use_color);
static char* log_content(char *buf, char *last,
        const char *format, va_list ap);
static char* log_level(char *buf, char *last,
        log_level_e level, int use_color);
static char* log_linefeed(char *buf, char *last);

// int log_vsnprintf(char *str, size_t size, const char *format, va_list ap);

// int log_snprintf(char *str, size_t size, const char *format, ...);

// char* log_vslprintf(char *str, char *last, const char *format, va_list ap);

// char* log_slprintf(char *str, char *last, const char *format, ...);

char* log_strerror(int err, char *buf, size_t size)
{
#if defined(STRERROR_R_CHAR_P)
    return strerror_r(err, buf, size);
#else
    int ret = strerror_r(err, buf, size);

    if (ret == 0)
        return buf;
    else
        return NULL;
#endif

}

static void file_writer(log_t *log, log_level_e level, const char *string)
{
    fprintf(log->file.out, "%s", string);
    fflush(log->file.out);
}

void log_init(void)
{
    init_list(&log_t_list);
    init_list(&log_domain_list);
    mempool_init(&log_pool, 8);
    mempool_init(&domain_pool, 64);

    log_add_domain("core", LOG_DEFAULT);
    log_add_stderr();
}

void log_final(void)
{
    log_t *log, *saved_log;
    log_domain_t *domain, *saved_domain;

    log = list_first(&log_t_list);
    do
    {
        saved_log = list_first(&log_t_list);
        log_remove(log);
        log = list_next(log);
    }while(log != saved_log);
    mempool_destroy(&log_pool);

    domain = list_first(&log_domain_list);
    do
    {
        saved_domain = list_first(&log_domain_list);
        log_remove_domain(domain);
        domain = list_next(domain);
    }while(domain != saved_domain);
    mempool_destroy(&domain_pool);
}

void log_cycle(void)
{
    log_t *log = NULL;
    log = list_first(&log_t_list);
    do
    {
        switch(log->type)
        {
            case LOG_FILE_TYPE:
                file_cycle(log);
            default:
                break;
        }
        log = list_next(log);
    }while(log != list_first(&log_t_list));
}

log_t* log_add_stderr(void)
{
    log_t* log = NULL;
    log = add_log(LOG_STDERR_TYPE);
    log_assert(log);

    log->file.out = stderr;
    log->writer = file_writer;
    log->print.color = 1;

    return log;
}

log_t* log_add_file(const char* name)
{
    FILE *out = NULL;
    log_t *log = NULL;

    out = fopen(name, "a");
    if (!out) 
        return NULL;
    
    log = add_log(LOG_FILE_TYPE);
    log_assert(log);

    log->file.name = name;
    log->file.out = out;

    log->writer = file_writer;

    return log;
}

void log_remove(log_t* log)
{
    log_assert(log);

    list_free_node(&log_t_list, log);

    if (log->type == LOG_FILE_TYPE) 
    {
        log_assert(log->file.out);
        fclose(log->file.out);
        log->file.out = NULL;
    }

    mempool_free(&log_pool, log);
}

log_domain_t *log_add_domain(const char *name, log_level_e level)
{
    log_domain_t* domain = NULL;
    log_assert(name);

    mempool_alloc(&domain_pool, &domain);
    log_assert(domain);

    domain->name = name;
    domain->id = mempool_index(&domain_pool, domain);
    domain->level = level;

    tail_insert_list(&log_domain_list, domain);
    return domain;
}

void log_remove_domain(log_domain_t* domain)
{
    log_assert(domain);

    list_free_node(&log_domain_list, domain);

    mempool_free(&domain_pool, domain);
}

log_domain_t* log_find_domain(const char *name)
{
    log_domain_t* domain = NULL;
    log_assert(name);
    domain = list_first(&log_domain_list);
    do
    {
        if(!strcasecmp(domain->name, name))
            return domain;
        domain = list_next(domain);
    }while(domain != list_first(&log_domain_list));

    return NULL;
}

void log_set_domain_level(int id, log_level_e level)
{
    log_domain_t *domain = NULL;

    log_assert(id > 0 && id <= 64);

    domain = mempool_find(&domain_pool, id);
    log_assert(domain);

    domain->level = level;
}

log_level_e log_get_domain_level(int id)
{
    log_domain_t *domain = NULL;

    log_assert(id > 0 && id <= 64);

    domain = mempool_find(&domain_pool, id);
    log_assert(domain);

    return domain->level;    
}

const char *log_get_domain_name(int id)
{
    log_domain_t *domain = NULL;

    log_assert(id > 0 && id <= 64);

    domain = mempool_find(&domain_pool, id);
    log_assert(domain);

    return domain->name;
}
int log_get_domain_id(const char *name)
{
    log_domain_t *domain = NULL;

    log_assert(name);
    
    domain = log_find_domain(name);
    log_assert(domain);

    return domain->id;
}

#if 0
int log_config_domain(const char *domain, const char *level)
{

}  

void log_set_mask_level(const char *mask, log_level_e level)
{

}

void log_set_timestamp(log_ts_e ts_default, log_ts_e ts_file)
{

}

void log_hexdump_func(log_level_e level, int domain_id,
    const unsigned char *data, size_t len)
{


}

#endif
void log_install_domain(int *domain_id,
        const char *name, log_level_e level)
{
    log_domain_t* domain = NULL;

    log_assert(domain_id);
    log_assert(name);

    domain = log_find_domain(name);
    if (domain) {
        log_warn("`%s` log-domain duplicated", name);
        if (level != domain->level) {
            log_warn("[%s]->[%s] log-level changed",
                    level_strings[domain->level], level_strings[level]);
            log_set_domain_level(domain->id, level);
        }
    } else {
        domain = log_add_domain(name, level);
        log_assert(domain);
    }

    *domain_id = domain->id;
}   

void log_vprintf(log_level_e level, int id,
    int err, const char *file, int line, const char *func,
    int content_only, const char *format, va_list ap)
{
    log_t *log = NULL;
    log_domain_t *domain = NULL;

    char logstr[8192];
    char *p, *last;

    int wrote_stderr = 0;

    #if 0
    list_for_each(&log_t_list, log) {
        
        domain = mempool_find(&domain_pool, id);
        if (!domain) {
            fprintf(stderr, "No LogDomain[id:%d] in %s:%d", id, file, line);
            ogs_assert_if_reached();
        }
        if (domain->level < level)
            return;

        p = logstr;
        last = logstr + 8192;

        if (!content_only) {
            if (log->print.timestamp)
                p = log_timestamp(p, last, log->print.color);
            if (log->print.domain)
                p = log_domain(p, last, domain->name, log->print.color);
            if (log->print.level)
                p = log_level(p, last, level, log->print.color);
        }

        p = log_content(p, last, format, ap);

        if (err) {
            char errbuf[8192];
            p = ogs_slprintf(p, last, " (%d:%s)",
                    (int)err, ogs_strerror(err, errbuf, 8192));
        }

        if (!content_only) {
            if (log->print.fileline)
                p = ogs_slprintf(p, last, " (%s:%d)", file, line);
            if (log->print.function)
                p = ogs_slprintf(p, last, " %s()", func);
            if (log->print.linefeed) 
                p = log_linefeed(p, last);
        }

        log->writer(log, level, logstr);
        
        if (log->type == OGS_LOG_STDERR_TYPE)
            wrote_stderr = 1;
    }
    #endif
    log = list_first(&log_t_list);
    do
    {
        domain = mempool_find(&domain_pool, id);
        if (!domain) {
            fprintf(stderr, "No LogDomain[id:%d] in %s:%d", id, file, line);
            log_assert_if_reached();
        }
        if (domain->level < level)
            return;

        p = logstr;
        last = logstr + 8192;

        if (!content_only) {
            if (log->print.timestamp)
                p = log_timestamp(p, last, log->print.color);
            if (log->print.domain)
                p = log_domain(p, last, domain->name, log->print.color);
            if (log->print.level)
                p = log_level(p, last, level, log->print.color);
        }

        p = log_content(p, last, format, ap);

        if (err) {
            char errbuf[8192];
            p = log_slprintf(p, last, " (%d:%s)",
                    (int)err, log_strerror(err, errbuf, 8192));
        }

        if (!content_only) {
            if (log->print.fileline)
                p = log_slprintf(p, last, " (%s:%d)", file, line);
            if (log->print.function)
                p = log_slprintf(p, last, " %s()", func);
            if (log->print.linefeed) 
                p = log_linefeed(p, last);
        }

        log->writer(log, level, logstr);
        
        if (log->type == LOG_STDERR_TYPE)
            wrote_stderr = 1;
        log = list_next(log);
    }while(log != list_first(&log_t_list));

    if (!wrote_stderr)
    {
        int use_color = 0;
        use_color = 1;
        p = logstr;
        last = logstr + 8192;

        if (!content_only) {
            p = log_timestamp(p, last, use_color);
            p = log_level(p, last, level, use_color);
        }
        p = log_content(p, last, format, ap);
        if (!content_only) {
            p = log_slprintf(p, last, " (%s:%d)", file, line);
            p = log_slprintf(p, last, " %s()", func);
            p = log_linefeed(p, last);
        }

        fprintf(stderr, "%s", logstr);
        fflush(stderr);
    }
}

void log_printf(log_level_e level, int domain_id,
    int err, const char *file, int line, const char *func,
    int content_only, const char *format, ...)
{
    va_list args;

    va_start(args, format);
    log_vprintf(level, domain_id,
            err, file, line, func, content_only, format, args);
    va_end(args);
}

static log_t *add_log(log_type_e type)
{
    log_t *log = NULL;

    mempool_alloc(&log_pool, &log);
    log_assert(log);
    memset(log, 0, sizeof *log);

    log->type = type;

    log->print.timestamp = 1;
    log->print.domain = 1;
    log->print.level = 1;
    log->print.fileline = 1;
    log->print.linefeed = 1;

    tail_insert_list(&log_t_list, log);

    return log;
}

static int file_cycle(log_t *log)
{
    log_assert(log);
    log_assert(log->file.out);
    log_assert(log->file.name);

    fclose(log->file.out);
    log->file.out = fopen(log->file.name, "a");
    log_assert(log->file.out);

    return 0;
}


static char *log_timestamp(char *buf, char *last,
        int use_color)
{
    struct timeval tv;
    struct tm tm;
    char nowstr[32];

    gettimeofday(&tv, NULL);
    struct tm* tm_ = localtime(&tv.tv_sec);
    tm = *tm_;

    strftime(nowstr, sizeof nowstr, "%m/%d %H:%M:%S", &tm);

    buf = log_slprintf(buf, last, "%s%s.%03d%s: ",
            use_color ? TA_FGC_GREEN : "",
            nowstr, (int)(tv.tv_usec/1000),
            use_color ? TA_NOR : "");

    return buf;
}

static char *log_domain(char *buf, char *last,
        const char *name, int use_color)
{
    buf = log_slprintf(buf, last, "[%s%s%s] ",
            use_color ? TA_FGC_YELLOW : "",
            name,
            use_color ? TA_NOR : "");

    return buf;
}

static char *log_level(char *buf, char *last,
        log_level_e level, int use_color)
{
    const char *colors[] = {
        TA_NOR,
        TA_FGC_BOLD_RED, TA_FGC_BOLD_YELLOW, TA_FGC_BOLD_CYAN,
        TA_FGC_BOLD_GREEN, TA_FGC_BOLD_WHITE, TA_FGC_WHITE,
    };

    buf = log_slprintf(buf, last, "%s%s%s: ",
            use_color ? colors[level] : "",
            level_strings[level],
            use_color ? TA_NOR : "");

    return buf;
}

static char *log_content(char *buf, char *last,
        const char *format, va_list ap)
{
    va_list bp;

    va_copy(bp, ap);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
    buf = log_vslprintf(buf, last, format, bp);
#pragma GCC diagnostic pop
    va_end(bp);

    return buf;
}

static char *log_linefeed(char *buf, char *last)
{
#if defined(_WIN32)
    if (buf > last - 3)
        buf = last - 3;

    buf = log_slprintf(buf, last, "\r\n");
#else
    if (buf > last - 2)
        buf = last - 2;

    buf = log_slprintf(buf, last, "\n");
#endif

    return buf;
}


int log_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
    int r = -1;
    r = vsnprintf(str, size, format, ap);
    str[size-1] = '\0';

    return r;
}

int log_snprintf(char *str, size_t size, const char *format, ...)
{
    int r;
    va_list ap;

    va_start(ap, format);
    r = log_vsnprintf(str, size, format, ap);
    va_end(ap);

    return r;
}

char* log_vslprintf(char *str, char *last, const char *format, va_list ap)
{
    int r = -1;

    log_assert(last);

    if (!str)
        return NULL;

    if (str < last)
        r = log_vsnprintf(str, last - str, format, ap);

    return (str + r);
}

char* log_slprintf(char *str, char *last, const char *format, ...)
{
    char *r;
    va_list ap;

    va_start(ap, format);
    r = log_vslprintf(str, last, format, ap);
    va_end(ap);

    return r;
}