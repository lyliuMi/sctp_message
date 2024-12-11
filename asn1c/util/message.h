#ifndef OGS_ASN_MESSAGE_H
#define OGS_ASN_MESSAGE_H

#include "../asn1c/common/asn_internal.h"
#include "../asn1c/common/constr_TYPE.h"
#include "../../core/pkbuf.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifndef OGS_MAX_SDU_LEN
#define OGS_MAX_SDU_LEN 32768 /* Should Heap */
#endif

pkbuf_t* asn_encode_custom(const asn_TYPE_descriptor_t *td, void *sptr);
int asn_decode_custom(const asn_TYPE_descriptor_t *td,
        void *struct_ptr, size_t struct_size, pkbuf_t *pkbuf);
void asn_free_custom(const asn_TYPE_descriptor_t *td, void *sptr);

#ifdef __cplusplus
}
#endif

#endif

