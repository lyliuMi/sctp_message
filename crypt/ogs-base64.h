#ifndef OGS_BASE64_H
#define OGS_BASE64_H

#ifdef __cplusplus
extern "C" {
#endif

int ogs_base64_decode_len(const char *bufcoded);
int ogs_base64_decode(char *bufplain, const char *bufcoded);
int ogs_base64_decode_binary(
        unsigned char *bufplain, const char *bufcoded);

int ogs_base64_encode_len(int len);
int ogs_base64_encode(
        char *encoded, const char *string, int len);
int ogs_base64_encode_binary(
        char *encoded, const unsigned char *string, int len);

int ogs_fbase64_decode(const char *header,
        const uint8_t *data, size_t data_size, ogs_datum_t *result);

int ogs_pem_decode_curve25519_key(const char *filename, uint8_t *key);
int ogs_pem_decode_secp256r1_key(const char *filename, uint8_t *key);

#ifdef __cplusplus
}
#endif

#endif /* OGS_BASE64_H */
