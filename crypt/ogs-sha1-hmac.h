#ifndef OGS_SHA1_HMAC_H
#define OGS_SHA1_HMAC_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    ogs_sha1_ctx ctx_inside;
    ogs_sha1_ctx ctx_outside;

    /* for hmac_reinit */
    ogs_sha1_ctx ctx_inside_reinit;
    ogs_sha1_ctx ctx_outside_reinit;

    uint8_t block_ipad[OGS_SHA1_BLOCK_SIZE];
    uint8_t block_opad[OGS_SHA1_BLOCK_SIZE];
} ogs_hmac_sha1_ctx;

void ogs_hmac_sha1_init(ogs_hmac_sha1_ctx *ctx, const uint8_t *key,
                      uint32_t key_size);
void ogs_hmac_sha1_reinit(ogs_hmac_sha1_ctx *ctx);
void ogs_hmac_sha1_update(ogs_hmac_sha1_ctx *ctx, const uint8_t *message,
                        uint32_t message_len);
void ogs_hmac_sha1_final(ogs_hmac_sha1_ctx *ctx, uint8_t *mac,
                       uint32_t mac_size);
void ogs_hmac_sha1(const uint8_t *key, uint32_t key_size,
                 const uint8_t *message, uint32_t message_len,
                 uint8_t *mac, uint32_t mac_size);

#ifdef __cplusplus
}
#endif

#endif /* OGS_SHA1_HMAC_H */
