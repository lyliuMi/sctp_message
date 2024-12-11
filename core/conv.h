#ifndef OGS_CONV_H
#define OGS_CONV_H

#include "core.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

int ogs_ascii_to_hex(char *in, int in_len, void *out, int out_len);
static inline void* ogs_hex_from_string(
        const char *str, void *out, int out_len)
{
    ogs_ascii_to_hex((char*)str, strlen(str), out, out_len);
    return out;
}

void *ogs_hex_to_ascii(const void *in, int in_len, void *out, int out_len);
void *ogs_uint64_to_buffer(uint64_t num, int size, void *buffer);
uint64_t ogs_buffer_to_uint64(void *buffer, int size);
void *ogs_bcd_to_buffer(const char *in, void *out, int *out_len);
void *ogs_bcd_to_buffer_reverse_order(const char *in, void *out, int *out_len);
void *ogs_buffer_to_bcd(uint8_t *in, int in_len, void *out);

char ogs_from_hex(char ch);
char ogs_to_hex(char ch);

char *ogs_uint24_to_0string(ogs_uint24_t x);
char *ogs_uint28_to_0string(uint32_t x);
char *ogs_uint32_to_0string(uint32_t x);
char *ogs_uint36_to_0string(uint64_t x);
char *ogs_uint64_to_0string(uint64_t x);
char *ogs_uint64_to_string(uint64_t x);
char *ogs_left_trimcharacter(char *str, char to_remove);
char *ogs_cpystrn(char *dst, const char *src, size_t dst_size);
ogs_uint24_t ogs_uint24_from_string(char *str);
uint64_t ogs_uint64_from_string(char *str);

double *ogs_alloc_double(double value);

#define ogs_msprintf(...) \
    ogs_talloc_asprintf(__VA_ARGS__)

char *ogs_talloc_asprintf(const char *fmt, ...);

char* strdup(const char* src);

#ifdef __cplusplus
}
#endif

#endif /* OGS_CONV_H */
