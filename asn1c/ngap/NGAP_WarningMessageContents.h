/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_WarningMessageContents_H_
#define	_NGAP_WarningMessageContents_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NGAP_WarningMessageContents */
typedef OCTET_STRING_t	 NGAP_WarningMessageContents_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NGAP_WarningMessageContents_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_WarningMessageContents;
asn_struct_free_f NGAP_WarningMessageContents_free;
asn_struct_print_f NGAP_WarningMessageContents_print;
asn_constr_check_f NGAP_WarningMessageContents_constraint;
per_type_decoder_f NGAP_WarningMessageContents_decode_aper;
per_type_encoder_f NGAP_WarningMessageContents_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_WarningMessageContents_H_ */
#include <asn_internal.h>