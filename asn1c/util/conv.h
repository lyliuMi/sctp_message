#ifndef ASN_CONV_H
#define ASN_CONV_H

#include "../asn1c/common/asn_internal.h"
#include "../asn1c/common/OCTET_STRING.h"
#include "../asn1c/common/BIT_STRING.h"
#include "assert.h"
#include <stdlib.h>
#include "../core/core.h"

#ifdef __cplusplus
extern "C" {
#endif

// #define OGS_MAX_SDU_LEN 32678
typedef struct uint24_s {
    uint32_t v:24;
}  __attribute__ ((packed)) uint24_t;

#define ASN_CLEAR_DATA(__dATA) \
    do { \
        assert((__dATA)); \
        if ((__dATA)->buf) { \
            FREEMEM((__dATA)->buf); \
            (__dATA)->buf = NULL; \
            (__dATA)->size = 0; \
        } \
    } while(0)
#define ASN_STORE_DATA(__dST, __sRC) \
    do { \
        assert((__sRC)); \
        assert((__sRC)->buf); \
        assert((__dST)); \
        ASN_CLEAR_DATA(__dST); \
        (__dST)->size = (__sRC)->size; \
        (__dST)->buf = CALLOC((__dST)->size, sizeof(uint8_t)); \
        memcpy((__dST)->buf, (__sRC)->buf, (__dST)->size); \
    } while(0)

void asn_uint8_to_OCTET_STRING(
        uint8_t uint8, OCTET_STRING_t* octet_string);
void asn_uint16_to_OCTET_STRING(
        uint16_t uint16, OCTET_STRING_t* octet_string);
// void asn_uint24_to_OCTET_STRING(
//         ogs_uint24_t uint24, OCTET_STRING_t *octet_string);
void asn_uint32_to_OCTET_STRING(
        uint32_t uint32, OCTET_STRING_t* octet_string);

void asn_OCTET_STRING_to_uint8(
        OCTET_STRING_t* octet_string, uint8_t* uint8);
void asn_OCTET_STRING_to_uint16(
        OCTET_STRING_t* octet_string, uint16_t* uint16);
// void asn_OCTET_STRING_to_uint24(
//         OCTET_STRING_t *octet_string, ogs_uint24_t *uint24);
void asn_OCTET_STRING_to_uint32(
        OCTET_STRING_t* octet_string, uint32_t* uint32);

void asn_buffer_to_OCTET_STRING(
        void* buf, int size, OCTET_STRING_t* octet_string);

void asn_buffer_to_BIT_STRING(
        void* buf, int size, int unused, BIT_STRING_t* bit_string);
void asn_uint32_to_BIT_STRING(
        uint32_t uint32, uint8_t bitsize, BIT_STRING_t* bit_string);
void asn_BIT_STRING_to_uint32(BIT_STRING_t* bit_string, uint32_t* uint32);

// int asn_BIT_STRING_to_ip(
//         BIT_STRING_t *bit_string, ogs_ip_t *ip);
// int asn_ip_to_BIT_STRING(
//         ogs_ip_t *ip, BIT_STRING_t *bit_string);

int asn_copy_ie(
        const asn_TYPE_descriptor_t* td, void* src, void* dst);

///////////////////////

int ascii_to_hex(char* in, int in_len, void* out, int out_len);
static inline void* hex_from_string(
        const char* str, void* out, int out_len)
{
    ascii_to_hex((char*)str, strlen(str), out, out_len);
    return out;
}

// void *ogs_hex_to_ascii(const void *in, int in_len, void *out, int out_len);
void* uint64_to_buffer(uint64_t num, int size, void* buffer);
uint64_t buffer_to_uint64(void* buffer, int size);
void* bcd_to_buffer(const char* in, void* out, int* out_len);
void* bcd_to_buffer_reverse_order(const char* in, void* out, int* out_len);
void* buffer_to_bcd(uint8_t* in, int in_len, void* out);

char from_hex(char ch);
char to_hex(char ch);

// char *ogs_uint24_to_0string(uint24_t x);
// char *ogs_uint28_to_0string(uint32_t x);
// char *ogs_uint32_to_0string(uint32_t x);
// char *ogs_uint36_to_0string(uint64_t x);
// char *ogs_uint64_to_0string(uint64_t x);
// char *ogs_uint64_to_string(uint64_t x);

// ogs_uint24_t ogs_uint24_from_string(char *str);
// uint64_t ogs_uint64_from_string(char *str);

// double *ogs_alloc_double(double value);

#ifdef __cplusplus
}
#endif

#endif /* OGS_ASN_CONV_H */
