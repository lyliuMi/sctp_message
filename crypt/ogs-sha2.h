#ifndef OGS_SHA2_H
#define OGS_SHA2_H

#ifdef __cplusplus
extern "C" {
#endif

#define OGS_SHA224_DIGEST_SIZE ( 224 / 8)
#define OGS_SHA256_DIGEST_SIZE ( 256 / 8)
#define OGS_SHA384_DIGEST_SIZE ( 384 / 8)
#define OGS_SHA512_DIGEST_SIZE ( 512 / 8)

#define OGS_SHA256_BLOCK_SIZE  ( 512 / 8)
#define OGS_SHA512_BLOCK_SIZE  (1024 / 8)
#define OGS_SHA384_BLOCK_SIZE  OGS_SHA512_BLOCK_SIZE
#define OGS_SHA224_BLOCK_SIZE  OGS_SHA256_BLOCK_SIZE

typedef struct {
    uint32_t tot_len;
    uint32_t len;
    uint8_t block[2 * OGS_SHA256_BLOCK_SIZE];
    uint32_t h[8];
} ogs_sha256_ctx;

typedef struct {
    uint32_t tot_len;
    uint32_t len;
    uint8_t block[2 * OGS_SHA512_BLOCK_SIZE];
    uint64_t h[8];
} ogs_sha512_ctx;

typedef ogs_sha512_ctx ogs_sha384_ctx;
typedef ogs_sha256_ctx ogs_sha224_ctx;

void ogs_sha224_init(ogs_sha224_ctx *ctx);
void ogs_sha224_update(ogs_sha224_ctx *ctx, const uint8_t *message,
        uint32_t len);
void ogs_sha224_final(ogs_sha224_ctx *ctx, uint8_t *digest);
void ogs_sha224(const uint8_t *message, uint32_t len, uint8_t *digest);

void ogs_sha256_init(ogs_sha256_ctx * ctx);
void ogs_sha256_update(ogs_sha256_ctx *ctx, const uint8_t *message,
                   uint32_t len);
void ogs_sha256_final(ogs_sha256_ctx *ctx, uint8_t *digest);
void ogs_sha256(const uint8_t *message, uint32_t len, uint8_t *digest);

void ogs_sha384_init(ogs_sha384_ctx *ctx);
void ogs_sha384_update(ogs_sha384_ctx *ctx, const uint8_t *message,
                   uint32_t len);
void ogs_sha384_final(ogs_sha384_ctx *ctx, uint8_t *digest);
void ogs_sha384(const uint8_t *message, uint32_t len, uint8_t *digest);

void ogs_sha512_init(ogs_sha512_ctx *ctx);
void ogs_sha512_update(ogs_sha512_ctx *ctx, const uint8_t *message,
                   uint32_t len);
void ogs_sha512_final(ogs_sha512_ctx *ctx, uint8_t *digest);
void ogs_sha512(const uint8_t *message, uint32_t len, uint8_t *digest);

#ifdef __cplusplus
}
#endif

#endif /* OGS_SHA2_H */
