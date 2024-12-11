#ifndef OGS_AES_CMAC_H
#define OGS_AES_CMAC_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Caculate CMAC value
 *
 * @param cmac
 * @param key
 * @param msg
 * @param len
 *
 * @return OGS_OK
 *         OGS_ERROR
 */
int ogs_aes_cmac_calculate(uint8_t *cmac, const uint8_t *key,
        const uint8_t *msg, const uint32_t len);

/**
 * Verify CMAC value
 *
 * @param cmac
 * @param key
 * @param msg
 * @param len
 *
 * @return OGS_OK
 *         OGS_ERROR
 *         OGS_ERR_INVALID_CMAC
 */
#define OGS_ERR_INVALID_CMAC -2
int ogs_aes_cmac_verify(uint8_t *cmac, const uint8_t *key,
        const uint8_t *msg, const uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* OGS_AES_CMAC_H */
