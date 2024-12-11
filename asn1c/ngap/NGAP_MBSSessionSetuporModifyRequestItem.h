/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_MBSSessionSetuporModifyRequestItem_H_
#define	_NGAP_MBSSessionSetuporModifyRequestItem_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_MBS-SessionID.h"
#include "NGAP_MBS-AreaSessionID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_AssociatedMBSQosFlowSetuporModifyRequestList;
struct NGAP_QosFlowListWithCause;
struct NGAP_ProtocolExtensionContainer;

/* NGAP_MBSSessionSetuporModifyRequestItem */
typedef struct NGAP_MBSSessionSetuporModifyRequestItem {
	NGAP_MBS_SessionID_t	 mBS_SessionID;
	NGAP_MBS_AreaSessionID_t	*mBS_AreaSessionID;	/* OPTIONAL */
	struct NGAP_AssociatedMBSQosFlowSetuporModifyRequestList	*associatedMBSQosFlowSetuporModifyRequestList;	/* OPTIONAL */
	struct NGAP_QosFlowListWithCause	*mBS_QosFlowToReleaseList;	/* OPTIONAL */
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_MBSSessionSetuporModifyRequestItem_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_MBSSessionSetuporModifyRequestItem;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_MBSSessionSetuporModifyRequestItem_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_MBSSessionSetuporModifyRequestItem_1[5];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_MBSSessionSetuporModifyRequestItem_H_ */
#include <asn_internal.h>
