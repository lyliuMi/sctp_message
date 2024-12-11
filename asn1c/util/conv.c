#include "conv.h"
#include <ctype.h>
void asn_uint8_to_OCTET_STRING(
        uint8_t uint8, OCTET_STRING_t *octet_string)
{
    assert(octet_string);

    octet_string->size = 1;
    octet_string->buf = CALLOC(octet_string->size, sizeof(uint8_t));

    octet_string->buf[0] = uint8;
}

void asn_uint16_to_OCTET_STRING(
        uint16_t uint16, OCTET_STRING_t *octet_string)
{
    assert(octet_string);

    octet_string->size = 2;
    octet_string->buf = CALLOC(octet_string->size, sizeof(uint8_t));

    octet_string->buf[0] = uint16 >> 8;
    octet_string->buf[1] = uint16;
}

// void asn_uint24_to_OCTET_STRING(
//         uint24_t uint24, OCTET_STRING_t *octet_string)
// {
//     assert(octet_string);

//     octet_string->size = 3;
//     octet_string->buf = CALLOC(octet_string->size, sizeof(uint8_t));

//     octet_string->buf[0] = uint24.v >> 16;
//     octet_string->buf[1] = uint24.v >> 8;
//     octet_string->buf[2] = uint24.v;
// }

void asn_uint32_to_OCTET_STRING(
        uint32_t uint32, OCTET_STRING_t *octet_string)
{
    assert(octet_string);

    octet_string->size = 4;
    octet_string->buf = CALLOC(octet_string->size, sizeof(uint8_t));

    octet_string->buf[0] = uint32 >> 24;
    octet_string->buf[1] = uint32 >> 16;
    octet_string->buf[2] = uint32 >> 8;
    octet_string->buf[3] = uint32;
}

void asn_OCTET_STRING_to_uint8(
        OCTET_STRING_t *octet_string, uint8_t *uint8)
{
    assert(octet_string);
    assert(uint8);

    *uint8 = octet_string->buf[0];
}
void asn_OCTET_STRING_to_uint16(
        OCTET_STRING_t *octet_string, uint16_t *uint16)
{
    assert(octet_string);
    assert(uint16);

    *uint16 = (octet_string->buf[0] << 8) + octet_string->buf[1];
}
// void asn_OCTET_STRING_to_uint24(
//         OCTET_STRING_t *octet_string, ogs_uint24_t *uint24)
// {
//     assert(octet_string);
//     assert(uint24);

//     memcpy(uint24, octet_string->buf, sizeof(ogs_uint24_t));
//     *uint24 = ogs_be24toh(*uint24);
// }
void asn_OCTET_STRING_to_uint32(
        OCTET_STRING_t *octet_string, uint32_t *uint32)
{
    assert(octet_string);
    assert(uint32);

    *uint32 = (octet_string->buf[0] << 24) + (octet_string->buf[1] << 16) +
                (octet_string->buf[2] << 8) + octet_string->buf[3];
}

void asn_buffer_to_OCTET_STRING(
        void *buf, int size, OCTET_STRING_t *octet_string)
{
    octet_string->size = size;
    octet_string->buf = CALLOC(octet_string->size, sizeof(uint8_t));

    memcpy(octet_string->buf, buf, size);
}

void asn_buffer_to_BIT_STRING(
        void *buf, int size, int unused, BIT_STRING_t *bit_string)
{
    bit_string->size = size;
    bit_string->buf = CALLOC(bit_string->size, sizeof(uint8_t));
    bit_string->bits_unused = unused;

    memcpy(bit_string->buf, buf, size);
}

void asn_uint32_to_BIT_STRING(
        uint32_t uint32, uint8_t bitsize, BIT_STRING_t *bit_string)
{
    char tmp[32];
    uint64_t uint64;
    assert(bit_string);

    uint64 = uint32;
    uint64_to_buffer(
            uint64 << ((32 - bitsize) % 8), (bitsize + 7) / 8, tmp);
    asn_buffer_to_BIT_STRING(
            tmp, (bitsize + 7) / 8, (32 - bitsize) % 8, bit_string);
}

void asn_BIT_STRING_to_uint32(BIT_STRING_t *bit_string, uint32_t *uint32)
{
    assert(bit_string);
    assert(uint32);

    *uint32 = buffer_to_uint64(bit_string->buf, bit_string->size)
                    >> bit_string->bits_unused;
}

// int asn_BIT_STRING_to_ip(BIT_STRING_t *bit_string, ogs_ip_t *ip)
// {
//     char buf[OGS_ADDRSTRLEN], buf2[OGS_ADDRSTRLEN];

//     assert(bit_string);
//     assert(ip);

//     memset(ip, 0, sizeof(*ip));

//     if (bit_string->size == OGS_IPV4V6_LEN) {
//         ip->ipv4 = 1;
//         ip->ipv6 = 1;
//         memcpy(&ip->addr, bit_string->buf, OGS_IPV4_LEN);
//         memcpy(&ip->addr6, bit_string->buf+OGS_IPV4_LEN, OGS_IPV6_LEN);
//         // ogs_debug("    IPv4[%s] IPv6[%s]",
//         //     OGS_INET_NTOP(&ip->addr, buf),
//         //     OGS_INET6_NTOP(&ip->addr6, buf2));
//     } else if (bit_string->size == OGS_IPV4_LEN) {
//         ip->ipv4 = 1;
//         memcpy(&ip->addr, bit_string->buf, OGS_IPV4_LEN);
//         // ogs_debug("    IPv4[%s]", OGS_INET_NTOP(&ip->addr, buf));
//     } else if (bit_string->size == OGS_IPV6_LEN) {
//         ip->ipv6 = 1;
//         memcpy(&ip->addr6, bit_string->buf, OGS_IPV6_LEN);
//         // ogs_debug("    IPv6[%s]", OGS_INET_NTOP(&ip->addr6, buf));
//     } else {
//         // ogs_error("ogs_asn_BIT_STRING_to_ip(size=%d) failed", bit_string->size);
//         return -1;
//     }

//     ip->len = bit_string->size;

//     return 0;
// }

// int asn_ip_to_BIT_STRING(ogs_ip_t *ip, BIT_STRING_t *bit_string)
// {
//     char buf[OGS_ADDRSTRLEN], buf2[OGS_ADDRSTRLEN];

//     ogs_assert(ip);
//     ogs_assert(bit_string);

//     if (ip->ipv4 && ip->ipv6) {
//         bit_string->size = OGS_IPV4V6_LEN;
//         bit_string->buf = CALLOC(bit_string->size, sizeof(uint8_t));
//         memcpy(bit_string->buf, &ip->addr, OGS_IPV4_LEN);
//         memcpy(bit_string->buf+OGS_IPV4_LEN, &ip->addr6, OGS_IPV6_LEN);
//         ogs_debug("    IPv4[%s] IPv6[%s]",
//             OGS_INET_NTOP(&ip->addr, buf),
//             OGS_INET6_NTOP(&ip->addr6, buf2));
//     } else if (ip->ipv4) {
//         bit_string->size = OGS_IPV4_LEN;
//         bit_string->buf = CALLOC(bit_string->size, sizeof(uint8_t));
//         memcpy(bit_string->buf, &ip->addr, OGS_IPV4_LEN);
//         ogs_debug("    IPv4[%s]", OGS_INET_NTOP(&ip->addr, buf));
//     } else if (ip->ipv6) {
//         bit_string->size = OGS_IPV6_LEN;
//         bit_string->buf = CALLOC(bit_string->size, sizeof(uint8_t));
//         memcpy(bit_string->buf, &ip->addr6, OGS_IPV6_LEN);
//         ogs_debug("    IPv6[%s]", OGS_INET_NTOP(&ip->addr6, buf));
//     } else {
//         ogs_error("No IPv4 or IPv6");
//         return OGS_ERROR;
//     }

//     return OGS_OK;
// }

int asn_copy_ie(const asn_TYPE_descriptor_t *td, void *src, void *dst)
{
    asn_enc_rval_t enc_ret = {0};
    asn_dec_rval_t dec_ret = {0};
    uint8_t *buffer = NULL;

    assert(td);
    assert(src);
    assert(dst);

    buffer = malloc(OGS_MAX_SDU_LEN);
    if (!buffer) {
        // ogs_error("ogs_calloc() failed");
        return -1;
    }

    enc_ret = aper_encode_to_buffer(td, NULL, src, buffer, OGS_MAX_SDU_LEN);
    if (enc_ret.encoded < 0) {
        // ogs_error("aper_encode_to_buffer() failed[%d]", (int)enc_ret.encoded);
        free(buffer);
        return -1;
    }

    dec_ret = aper_decode(NULL, td, (void **)&dst,
            buffer, ((enc_ret.encoded + 7) / 8), 0, 0);

    if (dec_ret.code != RC_OK) {
        // ogs_error("aper_decode() failed[%d]", dec_ret.code);
        free(buffer);
        return -1;
    }

    free(buffer);

    return 0;
}
///////////////////////////////////////////
int ascii_to_hex(char *in, int in_len, void *out, int out_len)
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

// void *ogs_hex_to_ascii(const void *in, int in_len, void *out, int out_len)
// {
//     char *p, *last;
//     int i = 0, l, off = 0;

//     p = out;
//     last = p + out_len;
//     p[0] = 0;

//     l = (in_len - off) > out_len ? out_len : in_len - off;
//     for (i = 0; i < l; i++) {
//         p = ogs_slprintf(p, last, "%02x", ((char*)in)[off+i] & 0xff);
//     }

//     return out;
// }

void* uint64_to_buffer(uint64_t num, int size, void *buffer)
{
    int i;
    uint8_t *buffer_p = buffer;
    for (i = 0; i < size; i++)
        buffer_p[i] = (num >> ((size-1-i) * 8)) & 0xff;

    return buffer;
}

uint64_t buffer_to_uint64(void *buffer, int size)
{
    uint64_t num = 0;
    uint8_t *buffer_p = buffer;
    int i;

    for (i = 0; i < size; i++) {
        num |= (((uint64_t)buffer_p[i]) << ((size-1-i) * 8));
    }

    return num;
}

void* bcd_to_buffer(const char *in, void *out, int *out_len)
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

void* bcd_to_buffer_reverse_order(const char *in, void *out, int *out_len)
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

void* buffer_to_bcd(uint8_t *in, int in_len, void *out)
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

char from_hex(char ch)
{
    return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

char to_hex(char ch)
{
    static char hex[] = "0123456789ABCDEF";
    return hex[ch & 15];
}

// char *ogs_uint24_to_0string(ogs_uint24_t x)
// {
//     return ogs_msprintf("%06x", x.v);
// }

// char *ogs_uint28_to_0string(uint32_t x)
// {
//     return ogs_msprintf("%07x", x);
// }

// char *ogs_uint32_to_0string(uint32_t x)
// {
//     return ogs_msprintf("%08x", x);
// }

// char *ogs_uint36_to_0string(uint64_t x)
// {
//     return ogs_msprintf("%09llx", (long long)x);
// }

// char *ogs_uint64_to_0string(uint64_t x)
// {
//     return ogs_msprintf("%016llx", (long long)x);
// }

// char *ogs_uint64_to_string(uint64_t x)
// {
//     char *str, *p, *dup;

//     str = ogs_uint64_to_0string(x);
//     if (!str) {
//         ogs_error("ogs_uint64_to_0string[%lld] failed", (long long)x);
//         return NULL;
//     }

//     p = ogs_left_trimcharacter(str, '0');
//     if (!p) {
//         ogs_error("ogs_left_trimcharacter[%s] failld", str);
//         return NULL;
//     }

//     dup = ogs_strdup(p);
//     ogs_free(str);

//     return dup;
// }

// ogs_uint24_t ogs_uint24_from_string(char *str)
// {
//     ogs_uint24_t x;

//     ogs_assert(str);

//     x.v = ogs_uint64_from_string(str);
//     return x;
// }

// uint64_t ogs_uint64_from_string(char *str)
// {
//     uint64_t x;

//     ogs_assert(str);

//     if (strlen(str) == 0)
//         return 0;

//     errno = 0;
//     x = strtoll(str, NULL, 16);

//     if ((errno == ERANGE && (x == LONG_MAX || x == LONG_MIN)) ||
//             (errno != 0 && x == 0)) {
//         ogs_log_message(OGS_LOG_FATAL, ogs_errno, "strtoll()) failed [%lld]",
//                 (long long)x);
//         ogs_assert_if_reached();
//     }

//     return x;
// }

// double *ogs_alloc_double(double value)
// {
//     double *mem = (double *)ogs_calloc(1, sizeof(double));
//     if (!mem) {
//         ogs_error("No memory");
//         return NULL;
//     }

//     *mem = value;

//     return mem;
// }
