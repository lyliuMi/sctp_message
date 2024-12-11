/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-PDU-Contents"
 * 	found in "../support/s1ap-r17.3.0/36413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_S1AP_E_RABToBeSwitchedULItem_H_
#define	_S1AP_E_RABToBeSwitchedULItem_H_


#include <asn_application.h>

/* Including external dependencies */
#include "S1AP_E-RAB-ID.h"
#include "S1AP_TransportLayerAddress.h"
#include "S1AP_GTP-TEID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct S1AP_ProtocolExtensionContainer;

/* S1AP_E-RABToBeSwitchedULItem */
typedef struct S1AP_E_RABToBeSwitchedULItem {
	S1AP_E_RAB_ID_t	 e_RAB_ID;
	S1AP_TransportLayerAddress_t	 transportLayerAddress;
	S1AP_GTP_TEID_t	 gTP_TEID;
	struct S1AP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_E_RABToBeSwitchedULItem_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_E_RABToBeSwitchedULItem;
extern asn_SEQUENCE_specifics_t asn_SPC_S1AP_E_RABToBeSwitchedULItem_specs_1;
extern asn_TYPE_member_t asn_MBR_S1AP_E_RABToBeSwitchedULItem_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_E_RABToBeSwitchedULItem_H_ */
#include <asn_internal.h>
