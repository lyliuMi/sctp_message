#ifndef OGS_NAS_SECURITY_H
#define OGS_NAS_SECURITY_H

#ifdef __cplusplus
extern "C" {
#endif

#define OGS_NAS_SECURITY_DOWNLINK_DIRECTION 1
#define OGS_NAS_SECURITY_UPLINK_DIRECTION 0

void ogs_nas_mac_calculate(uint8_t algorithm_identity,
    uint8_t *knas_int, uint32_t count, uint8_t bearer, 
    uint8_t direction, pkbuf_t *pkbuf, uint8_t *mac);

void ogs_nas_encrypt(uint8_t algorithm_identity,
    uint8_t *knas_enc, uint32_t count, uint8_t bearer, 
    uint8_t direction, pkbuf_t *pkbuf);

#ifdef __cplusplus
}
#endif

#endif /* OGS_NAS_SECURITY_H */
