#ifndef HEADER_SNOW3G_H
#define HEADER_SNOW3G_H

#if 0 /* modified by acetcom */
#include <openssl/opensslconf.h>
#else
// #include "core/ogs-core.h"
#endif

#ifdef OPENSSL_NO_SNOW3G
#error SNOW3G is disabled.
#endif

#include <stddef.h>
#include <stdint.h>

#define SNOW_ENCRYPT	1
#define SNOW_DECRYPT	0

#define SNOW_WORD_SIZE 4
#define SNOW_KEY_SIZE 16

#ifdef  __cplusplus
extern "C" {
#endif

struct snow_key_st {
  uint32_t key[4];
  uint32_t iv[4];
};

struct fsm_st {
  uint32_t r1;
  uint32_t r2;
  uint32_t r3;
};

typedef struct snow_ctx_st {
  uint32_t lfsr[SNOW_KEY_SIZE];
  struct fsm_st fsm;
} SNOW_CTX;

struct snow_key_st
#if 0
snow_array_to_key(const unsigned char key[16], const unsigned char iv[16]);
#else
snow_array_to_key(const unsigned char *key, const unsigned char *iv);
#endif

void
SNOW_set_key(struct snow_key_st key_iv, SNOW_CTX *ctx);

void
SNOW_gen_keystream(uint32_t *stream, size_t nb_word, SNOW_CTX *ctx);

void
SNOW_init(uint32_t countc, uint8_t bearer, uint8_t direction,
    const char *confidentiality_key, SNOW_CTX *ctx);

void
SNOW(size_t nb_byte, const unsigned char *in, unsigned char *out, SNOW_CTX *ctx);

#ifdef  __cplusplus
}
#endif

#endif /* !HEADER_SNOW_H */
