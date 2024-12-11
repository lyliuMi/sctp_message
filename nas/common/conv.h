#ifndef OGS_NAS_COMMON_CONV_H
#define OGS_NAS_COMMON_CONV_H

#include "ogs-nas-common.h"

#ifdef __cplusplus
extern "C" {
#endif

void ogs_nas_imeisv_to_bcd(
    ogs_nas_mobile_identity_imeisv_t *imeisv, uint8_t imeisv_len, char *bcd);
void *ogs_nas_imeisv_bcd_to_buffer(const char *in, uint8_t *out, int *out_len);

int ogs_nas_gprs_timer_from_sec(
        ogs_nas_gprs_timer_t *gprs_timer, long sec);
int ogs_nas_gprs_timer_3_from_sec(
        ogs_nas_gprs_timer_t *gprs_timer, long sec);

#ifdef __cplusplus
}
#endif

#endif /* OGS_NAS_COMMON_CONV_H */

