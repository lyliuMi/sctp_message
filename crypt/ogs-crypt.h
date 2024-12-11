#ifndef OGS_CRYPT_H
#define OGS_CRYPT_H

#include "../proto/ogs-proto.h"

#define OGS_CRYPT_INSIDE

#include "ogs-sha1.h"
#include "ogs-sha1-hmac.h"
#include "ogs-sha2.h"
#include "ogs-sha2-hmac.h"
#include "ogs-aes.h"
#include "ogs-aes-cmac.h"

#include "milenage.h"
#include "snow-3g.h"
#include "zuc.h"
#include "kasumi.h"
#include "ecc.h"

#include "ogs-kdf.h"
#include "ogs-base64.h"

#include "openssl/snow3g.h"

#undef OGS_CRYPT_INSIDE

#ifdef __cplusplus
extern "C" {
#endif

#define OGS_KEY_LEN                     16
#define OGS_IVEC_LEN                    16
#define OGS_AMF_LEN                     2
#define OGS_RAND_LEN                    16
#define OGS_AUTN_LEN                    16
#define OGS_AUTS_LEN                    14
#define OGS_MAX_RES_LEN                 16
#define OGS_MAC_S_LEN                   8

#define OGS_SQN_XOR_AK_LEN              6
#define OGS_AK_LEN                      6
#define OGS_SQN_LEN                     6
#define OGS_MAX_SQN                     0xffffffffffff

#define OGS_HASH_MME_LEN                8

#define OGS_ECCKEY_LEN                  32
#define OGS_MACTAG_LEN                  8

#define OGS_KEYSTRLEN(x)                ((x*2)+1)

int curve25519_donna(
        uint8_t *mypublic, const uint8_t *secret, const uint8_t *basepoint);

#ifdef __cplusplus
}
#endif

#endif /* OGS_CRYPT_H */
