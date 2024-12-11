
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include "conv.h"
#include <errno.h>

char *ogs_talloc_asprintf(const char *fmt, ...) 
{
    va_list args;
    va_start(args, fmt);

    // 计算格式化后的字符串所需长度
    int len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    if (len < 0) {
        return NULL; // 格式化失败
    }

    // 为字符串分配内存
    char *result = malloc(len + 1); // +1 为字符串终止符 '\0'
    if (!result) {
        return NULL; // 内存分配失败
    }

    // 将格式化后的字符串写入分配的内存
    va_start(args, fmt);
    vsnprintf(result, len + 1, fmt, args);
    va_end(args);

    return result;
}
char *ogs_cpystrn(char *dst, const char *src, size_t dst_size)
{
    char *d = dst, *end;

    if (dst_size == 0) {
        return (dst);
    }

    if (src) {
        end = dst + dst_size - 1;

        for (; d < end; ++d, ++src) {
            if (!(*d = *src)) {
                return (d);
            }
        }
    }

    *d = '\0';    /* always null terminate */

    return (d);
}
char *ogs_left_trimcharacter(char *str, char to_remove)
{
    if (str == NULL) {
        return NULL;
    } else if (*str == 0) {
        return str;
    }

    while(*str == to_remove) str++;

    return str;
}

char* strdup(const char* src)
{
    char* tmp = (char*)malloc(strlen(src)+1);
    memcpy(tmp, src, strlen(src));
    return tmp;
}
int ogs_ascii_to_hex(char *in, int in_len, void *out, int out_len)
{
    int i = 0, j = 0, k = 0, hex;
    uint8_t *out_p = out;

    while(i < in_len && j < out_len) {
        if (!isspace(in[i])) {
            hex = isdigit(in[i]) ? in[i] - '0' :
                islower(in[i]) ? in[i] - 'a' + 10 : in[i] - 'A' + 10;
            if ((k & 0x1) == 0) {
                out_p[j] = (hex << 4);
            } else {
                out_p[j] |= hex;
                j++;
            }
            k++;
        }
        i++;
    }

    return j;
}

void *ogs_hex_to_ascii(const void *in, int in_len, void *out, int out_len)
{
    char *p, *last;
    int i = 0, l, off = 0;

    p = out;
    last = p + out_len;
    p[0] = 0;

    l = (in_len - off) > out_len ? out_len : in_len - off;
    for (i = 0; i < l; i++) {
        p = log_slprintf(p, last, "%02x", ((char*)in)[off+i] & 0xff);
    }

    return out;
}

void *ogs_uint64_to_buffer(uint64_t num, int size, void *buffer)
{
    int i;
    uint8_t *buffer_p = buffer;
    for (i = 0; i < size; i++)
        buffer_p[i] = (num >> ((size-1-i) * 8)) & 0xff;

    return buffer;
}

uint64_t ogs_buffer_to_uint64(void *buffer, int size)
{
    uint64_t num = 0;
    uint8_t *buffer_p = buffer;
    int i;

    for (i = 0; i < size; i++) {
        num |= (((uint64_t)buffer_p[i]) << ((size-1-i) * 8));
    }

    return num;
}

void *ogs_bcd_to_buffer(const char *in, void *out, int *out_len)
{
    int i = 0;
    uint8_t *out_p = out;
    int in_len = strlen(in);

    for (i = 0; i < in_len; i++) {
        if (i & 0x01)
            out_p[i>>1] = out_p[i>>1] | (((in[i] - 0x30) << 4) & 0xF0);
        else
            out_p[i>>1] = (in[i] - 0x30) & 0x0F;
    }

    *out_len = (in_len + 1) / 2;
    if (in_len & 0x01) {
        out_p[(*out_len)-1] |= 0xF0;
    }

    return out;
}

void *ogs_bcd_to_buffer_reverse_order(const char *in, void *out, int *out_len)
{
    int i = 0;
    uint8_t *out_p = out;
    int in_len = strlen(in);

    for (i = 0; i < in_len; i++) {
        if (i & 0x01)
            out_p[i>>1] = out_p[i>>1] | ((in[i] - 0x30) & 0x0F);
        else
            out_p[i>>1] = ((in[i] - 0x30) << 4) & 0xF0;
    }

    *out_len = (in_len + 1) / 2;
    if (in_len & 0x01) {
        out_p[(*out_len)-1] |= 0xF0;
    }

    return out;
}

void *ogs_buffer_to_bcd(uint8_t *in, int in_len, void *out)
{
    int i = 0;
    uint8_t *out_p = out;

    for (i = 0; i < in_len-1; i++) {
        out_p[i*2] = 0x30 + (in[i] & 0x0F);
        out_p[i*2+1] = 0x30 + ((in[i] & 0xF0) >> 4);
    }

    if ((in[i] & 0xF0) == 0xF0) {
        out_p[i*2] = 0x30 + (in[i] & 0x0F);
        out_p[i*2+1] = 0;
    } else {
        out_p[i*2] = 0x30 + (in[i] & 0x0F);
        out_p[i*2+1] = 0x30 + ((in[i] & 0xF0) >> 4);
        out_p[i*2+2] = 0;
    }

    return out;
}

char ogs_from_hex(char ch)
{
    return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

char ogs_to_hex(char ch)
{
    static char hex[] = "0123456789ABCDEF";
    return hex[ch & 15];
}

char *ogs_uint24_to_0string(ogs_uint24_t x)
{
    return ogs_msprintf("%06x", x.v);
}

char *ogs_uint28_to_0string(uint32_t x)
{
    return ogs_msprintf("%07x", x);
}

char *ogs_uint32_to_0string(uint32_t x)
{
    return ogs_msprintf("%08x", x);
}

char *ogs_uint36_to_0string(uint64_t x)
{
    return ogs_msprintf("%09llx", (long long)x);
}

char *ogs_uint64_to_0string(uint64_t x)
{
    return ogs_msprintf("%016llx", (long long)x);
}

char *ogs_uint64_to_string(uint64_t x)
{
    char *str, *p, *dup;

    str = ogs_uint64_to_0string(x);
    if (!str) {
        //("ogs_uint64_to_0string[%lld] failed", (long long)x);
        return NULL;
    }

    p = ogs_left_trimcharacter(str, '0');
    if (!p) {
        //("ogs_left_trimcharacter[%s] failld", str);
        return NULL;
    }

    dup = strdup(p);
    free(str);

    return dup;
}

ogs_uint24_t ogs_uint24_from_string(char *str)
{
    ogs_uint24_t x;

    assert(str);

    x.v = ogs_uint64_from_string(str);
    return x;
}

uint64_t ogs_uint64_from_string(char *str)
{
    uint64_t x;

    assert(str);

    if (strlen(str) == 0)
        return 0;

    errno = 0;
    x = strtoll(str, NULL, 16);

    if ((errno == ERANGE && (x == LONG_MAX || x == LONG_MIN)) ||
            (errno != 0 && x == 0)) {
        // ogs_log_message(OGS_LOG_FATAL, ogs_errno, "strtoll()) failed [%lld]",
        //         (long long)x);
        abort();
    }

    return x;
}

double *ogs_alloc_double(double value)
{
    double *mem = (double *)calloc(1, sizeof(double));
    if (!mem) {
        // //("No memory");
        return NULL;
    }

    *mem = value;

    return mem;
}
