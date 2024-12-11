/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_QosFlowIdentifier_H_
#define	_NGAP_QosFlowIdentifier_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NGAP_QosFlowIdentifier */
typedef long	 NGAP_QosFlowIdentifier_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NGAP_QosFlowIdentifier_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_QosFlowIdentifier;
asn_struct_free_f NGAP_QosFlowIdentifier_free;
asn_struct_print_f NGAP_QosFlowIdentifier_print;
asn_constr_check_f NGAP_QosFlowIdentifier_constraint;
per_type_decoder_f NGAP_QosFlowIdentifier_decode_aper;
per_type_encoder_f NGAP_QosFlowIdentifier_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_QosFlowIdentifier_H_ */
#include <asn_internal.h>
