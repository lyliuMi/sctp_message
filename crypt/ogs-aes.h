
#ifndef OGS_AES_H
#define OGS_AES_H

#ifdef __cplusplus
extern "C" {
#endif

#define OGS_AES_BLOCK_SIZE 16
#define OGS_AES_MAX_KEY_BITS 256

#define OGS_AES_KEYLENGTH(keybits) ((keybits)/8)
#define OGS_AES_RKLENGTH(keybits)  ((keybits)/8+28)
#define OGS_AES_NROUNDS(keybits)   ((keybits)/32+6)

int ogs_aes_setup_enc(uint32_t *rk, const uint8_t *key, int keybits);
int ogs_aes_setup_dec(uint32_t *rk, const uint8_t *key, int keybits);

void ogs_aes_encrypt(const uint32_t *rk, int nrounds,
        const uint8_t plaintext[16], uint8_t ciphertext[16]);
void ogs_aes_decrypt(const uint32_t *rk, int nrounds,
        const uint8_t ciphertext[16], uint8_t plaintext[16]);

int ogs_aes_cbc_encrypt(const uint8_t *key,
        const uint32_t keybits, uint8_t *ivec,
        const uint8_t *in, const uint32_t inlen,
        uint8_t *out, uint32_t *outlen);
int ogs_aes_cbc_decrypt(const uint8_t *key,
        const uint32_t keybits, uint8_t *ivec,
        const uint8_t *in, const uint32_t inlen,
        uint8_t *out, uint32_t *outlen);

int ogs_aes_ctr128_encrypt(const uint8_t *key,
        uint8_t *ivec, const uint8_t *in, const uint32_t inlen,
        uint8_t *out);

#ifdef __cplusplus
}
#endif

#endif /* OGS_AES_H */
