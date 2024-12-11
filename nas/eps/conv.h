#ifndef OGS_NAS_EPS_CONV_H
#define OGS_NAS_EPS_CONV_H

#include "ogs-nas-common.h"

#ifdef __cplusplus
extern "C" {
#endif

void ogs_nas_imsi_to_buffer(
    const ogs_nas_mobile_identity_imsi_t *imsi, uint8_t imsi_len,
    uint8_t *buf, uint8_t *buf_len);

void ogs_nas_eps_imsi_to_bcd(
    const ogs_nas_mobile_identity_imsi_t *imsi, uint8_t imsi_len, char *bcd);

#ifdef __cplusplus
}
#endif

#endif /* OGS_NAS_EPS_CONV_H */

