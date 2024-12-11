#ifndef MILENAGE_H
#define MILENAGE_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void milenage_generate(const uint8_t *opc, const uint8_t *amf, 
    const uint8_t *k, const uint8_t *sqn, const uint8_t *_rand, 
    uint8_t *autn, uint8_t *ik, uint8_t *ck, uint8_t *ak,
    uint8_t *res, size_t *res_len);
int milenage_auts(const uint8_t *opc, const uint8_t *k, 
    const uint8_t *_rand, const uint8_t *auts, uint8_t *sqn);
int gsm_milenage(const uint8_t *opc, const uint8_t *k, 
    const uint8_t *_rand, uint8_t *sres, uint8_t *kc);
int milenage_check(const uint8_t *opc, const uint8_t *k, 
    const uint8_t *sqn, const uint8_t *_rand, const uint8_t *autn, 
    uint8_t *ik, uint8_t *ck, uint8_t *res, size_t *res_len,
    uint8_t *auts);
int milenage_f1(const uint8_t *opc, const uint8_t *k, 
    const uint8_t *_rand, const uint8_t *sqn, const uint8_t *amf, 
    uint8_t *mac_a, uint8_t *mac_s);
int milenage_f2345(const uint8_t *opc, const uint8_t *k, 
    const uint8_t *_rand, uint8_t *res, uint8_t *ck, uint8_t *ik, 
    uint8_t *ak, uint8_t *akstar);

void milenage_opc(const uint8_t *k, const uint8_t *op,  uint8_t *opc);

#ifdef __cplusplus
}
#endif

#endif /* MILENAGE_H */
