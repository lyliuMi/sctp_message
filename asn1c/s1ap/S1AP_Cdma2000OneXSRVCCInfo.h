/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "../support/s1ap-r17.3.0/36413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_S1AP_Cdma2000OneXSRVCCInfo_H_
#define	_S1AP_Cdma2000OneXSRVCCInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "S1AP_Cdma2000OneXMEID.h"
#include "S1AP_Cdma2000OneXMSI.h"
#include "S1AP_Cdma2000OneXPilot.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct S1AP_ProtocolExtensionContainer;

/* S1AP_Cdma2000OneXSRVCCInfo */
typedef struct S1AP_Cdma2000OneXSRVCCInfo {
	S1AP_Cdma2000OneXMEID_t	 cdma2000OneXMEID;
	S1AP_Cdma2000OneXMSI_t	 cdma2000OneXMSI;
	S1AP_Cdma2000OneXPilot_t	 cdma2000OneXPilot;
	struct S1AP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_Cdma2000OneXSRVCCInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_Cdma2000OneXSRVCCInfo;
extern asn_SEQUENCE_specifics_t asn_SPC_S1AP_Cdma2000OneXSRVCCInfo_specs_1;
extern asn_TYPE_member_t asn_MBR_S1AP_Cdma2000OneXSRVCCInfo_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_Cdma2000OneXSRVCCInfo_H_ */
#include <asn_internal.h>
