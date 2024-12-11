

#include "ogs-crypt.h"

void ogs_hmac_sha1_init(ogs_hmac_sha1_ctx *ctx, const uint8_t *key,
                      uint32_t key_size)
{
    uint32_t fill;
    uint32_t num;

    uint8_t key_temp[OGS_SHA1_DIGEST_SIZE];
    int i;

    if (key_size == OGS_SHA1_BLOCK_SIZE) {
        memcpy(key_temp, key, sizeof(key_temp));
        num = OGS_SHA1_BLOCK_SIZE;
    } else {
        if (key_size > OGS_SHA1_BLOCK_SIZE){
            num = OGS_SHA1_DIGEST_SIZE;
            ogs_sha1(key, key_size, key_temp);
        } else { /* key_size > SHA1_BLOCK_SIZE */
            memcpy(key_temp, key, sizeof(key_temp));
            num = key_size;
        }
        fill = OGS_SHA1_BLOCK_SIZE - num;

        memset(ctx->block_ipad + num, 0x36, fill);
        memset(ctx->block_opad + num, 0x5c, fill);
    }

    for (i = 0; i < num; i++) {
        ctx->block_ipad[i] = key_temp[i] ^ 0x36;
        ctx->block_opad[i] = key_temp[i] ^ 0x5c;
    }

    ogs_sha1_init(&ctx->ctx_inside);
    ogs_sha1_update(&ctx->ctx_inside, ctx->block_ipad, OGS_SHA1_BLOCK_SIZE);

    ogs_sha1_init(&ctx->ctx_outside);
    ogs_sha1_update(&ctx->ctx_outside, ctx->block_opad,
                  OGS_SHA1_BLOCK_SIZE);

    /* for hmac_reinit */
    memcpy(&ctx->ctx_inside_reinit, &ctx->ctx_inside,
           sizeof(ogs_sha1_ctx));
    memcpy(&ctx->ctx_outside_reinit, &ctx->ctx_outside,
           sizeof(ogs_sha1_ctx));
}

void ogs_hmac_sha1_reinit(ogs_hmac_sha1_ctx *ctx)
{
    memcpy(&ctx->ctx_inside, &ctx->ctx_inside_reinit,
           sizeof(ogs_sha1_ctx));
    memcpy(&ctx->ctx_outside, &ctx->ctx_outside_reinit,
           sizeof(ogs_sha1_ctx));
}

void ogs_hmac_sha1_update(ogs_hmac_sha1_ctx *ctx, const uint8_t *message,
                        uint32_t message_len)
{
    ogs_sha1_update(&ctx->ctx_inside, message, message_len);
}

void ogs_hmac_sha1_final(ogs_hmac_sha1_ctx *ctx, uint8_t *mac,
                       uint32_t mac_size)
{
    uint8_t digest_inside[OGS_SHA1_DIGEST_SIZE];
    uint8_t mac_temp[OGS_SHA1_DIGEST_SIZE];

    ogs_sha1_final(&ctx->ctx_inside, digest_inside);
    ogs_sha1_update(&ctx->ctx_outside, digest_inside, OGS_SHA1_DIGEST_SIZE);
    ogs_sha1_final(&ctx->ctx_outside, mac_temp);
    memcpy(mac, mac_temp, mac_size);
}

void ogs_hmac_sha1(const uint8_t *key, uint32_t key_size,
          const uint8_t *message, uint32_t message_len,
          uint8_t *mac, uint32_t mac_size)
{
    ogs_hmac_sha1_ctx ctx;

    ogs_hmac_sha1_init(&ctx, key, key_size);
    ogs_hmac_sha1_update(&ctx, message, message_len);
    ogs_hmac_sha1_final(&ctx, mac, mac_size);
}
