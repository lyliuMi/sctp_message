/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_UserLocationInformationW_AGF_H_
#define	_NGAP_UserLocationInformationW_AGF_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_HFCNode-ID.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_UserLocationInformationW_AGF_PR {
	NGAP_UserLocationInformationW_AGF_PR_NOTHING,	/* No components present */
	NGAP_UserLocationInformationW_AGF_PR_globalLine_ID,
	NGAP_UserLocationInformationW_AGF_PR_hFCNode_ID,
	NGAP_UserLocationInformationW_AGF_PR_choice_Extensions
} NGAP_UserLocationInformationW_AGF_PR;

/* Forward declarations */
struct NGAP_GlobalLine_ID;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_UserLocationInformationW-AGF */
typedef struct NGAP_UserLocationInformationW_AGF {
	NGAP_UserLocationInformationW_AGF_PR present;
	union NGAP_UserLocationInformationW_AGF_u {
		struct NGAP_GlobalLine_ID	*globalLine_ID;
		NGAP_HFCNode_ID_t	 hFCNode_ID;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_UserLocationInformationW_AGF_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_UserLocationInformationW_AGF;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_UserLocationInformationW_AGF_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_UserLocationInformationW_AGF_1[3];
extern asn_per_constraints_t asn_PER_type_NGAP_UserLocationInformationW_AGF_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_UserLocationInformationW_AGF_H_ */
#include <asn_internal.h>
