
#ifndef OGS_SHA2_HMAC_H
#define OGS_SHA2_HMAC_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    ogs_sha224_ctx ctx_inside;
    ogs_sha224_ctx ctx_outside;

    /* for hmac_reinit */
    ogs_sha224_ctx ctx_inside_reinit;
    ogs_sha224_ctx ctx_outside_reinit;

    uint8_t block_ipad[OGS_SHA224_BLOCK_SIZE];
    uint8_t block_opad[OGS_SHA224_BLOCK_SIZE];
} ogs_hmac_sha224_ctx;

typedef struct {
    ogs_sha256_ctx ctx_inside;
    ogs_sha256_ctx ctx_outside;

    /* for hmac_reinit */
    ogs_sha256_ctx ctx_inside_reinit;
    ogs_sha256_ctx ctx_outside_reinit;

    uint8_t block_ipad[OGS_SHA256_BLOCK_SIZE];
    uint8_t block_opad[OGS_SHA256_BLOCK_SIZE];
} ogs_hmac_sha256_ctx;

typedef struct {
    ogs_sha384_ctx ctx_inside;
    ogs_sha384_ctx ctx_outside;

    /* for hmac_reinit */
    ogs_sha384_ctx ctx_inside_reinit;
    ogs_sha384_ctx ctx_outside_reinit;

    uint8_t block_ipad[OGS_SHA384_BLOCK_SIZE];
    uint8_t block_opad[OGS_SHA384_BLOCK_SIZE];
} ogs_hmac_sha384_ctx;

typedef struct {
    ogs_sha512_ctx ctx_inside;
    ogs_sha512_ctx ctx_outside;

    /* for hmac_reinit */
    ogs_sha512_ctx ctx_inside_reinit;
    ogs_sha512_ctx ctx_outside_reinit;

    uint8_t block_ipad[OGS_SHA512_BLOCK_SIZE];
    uint8_t block_opad[OGS_SHA512_BLOCK_SIZE];
} ogs_hmac_sha512_ctx;

void ogs_hmac_sha224_init(ogs_hmac_sha224_ctx *ctx, const uint8_t *key,
                      uint32_t key_size);
void ogs_hmac_sha224_reinit(ogs_hmac_sha224_ctx *ctx);
void ogs_hmac_sha224_update(ogs_hmac_sha224_ctx *ctx, const uint8_t *message,
                        uint32_t message_len);
void ogs_hmac_sha224_final(ogs_hmac_sha224_ctx *ctx, uint8_t *mac,
                       uint32_t mac_size);
void ogs_hmac_sha224(const uint8_t *key, uint32_t key_size,
                 const uint8_t *message, uint32_t message_len,
                 uint8_t *mac, uint32_t mac_size);

void ogs_hmac_sha256_init(ogs_hmac_sha256_ctx *ctx, const uint8_t *key,
                      uint32_t key_size);
void ogs_hmac_sha256_reinit(ogs_hmac_sha256_ctx *ctx);
void ogs_hmac_sha256_update(ogs_hmac_sha256_ctx *ctx, const uint8_t *message,
                        uint32_t message_len);
void ogs_hmac_sha256_final(ogs_hmac_sha256_ctx *ctx, uint8_t *mac,
                       uint32_t mac_size);
void ogs_hmac_sha256(const uint8_t *key, uint32_t key_size,
                 const uint8_t *message, uint32_t message_len,
                 uint8_t *mac, uint32_t mac_size);

void ogs_hmac_sha384_init(ogs_hmac_sha384_ctx *ctx, const uint8_t *key,
                      uint32_t key_size);
void ogs_hmac_sha384_reinit(ogs_hmac_sha384_ctx *ctx);
void ogs_hmac_sha384_update(ogs_hmac_sha384_ctx *ctx, const uint8_t *message,
                        uint32_t message_len);
void ogs_hmac_sha384_final(ogs_hmac_sha384_ctx *ctx, uint8_t *mac,
                       uint32_t mac_size);
void ogs_hmac_sha384(const uint8_t *key, uint32_t key_size,
                 const uint8_t *message, uint32_t message_len,
                 uint8_t *mac, uint32_t mac_size);

void ogs_hmac_sha512_init(ogs_hmac_sha512_ctx *ctx, const uint8_t *key,
                      uint32_t key_size);
void ogs_hmac_sha512_reinit(ogs_hmac_sha512_ctx *ctx);
void ogs_hmac_sha512_update(ogs_hmac_sha512_ctx *ctx, const uint8_t *message,
                        uint32_t message_len);
void ogs_hmac_sha512_final(ogs_hmac_sha512_ctx *ctx, uint8_t *mac,
                       uint32_t mac_size);
void ogs_hmac_sha512(const uint8_t *key, uint32_t key_size,
                 const uint8_t *message, uint32_t message_len,
                 uint8_t *mac, uint32_t mac_size);

#ifdef __cplusplus
}
#endif

#endif /* OGS_SHA2_HMAC_H */
