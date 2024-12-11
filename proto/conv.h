#ifndef OGS_PROTO_CONV_H
#define OGS_PROTO_CONV_H

#include "ogs-proto.h"

#ifdef __cplusplus
extern "C" {
#endif

void ogs_extract_digit_from_string(char *digit, char *string);

int ogs_paa_to_ip(const ogs_paa_t *paa, ogs_ip_t *ip);
int ogs_ip_to_paa(const ogs_ip_t *ip, ogs_paa_t *paa);

#ifdef __cplusplus
}
#endif

#endif /* OGS_PROTO_CONV_H */
