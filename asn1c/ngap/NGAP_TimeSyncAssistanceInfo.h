/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_TimeSyncAssistanceInfo_H_
#define	_NGAP_TimeSyncAssistanceInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_TimeSyncAssistanceInfo__timeDistributionIndication {
	NGAP_TimeSyncAssistanceInfo__timeDistributionIndication_enabled	= 0,
	NGAP_TimeSyncAssistanceInfo__timeDistributionIndication_disabled	= 1
	/*
	 * Enumeration is extensible
	 */
} e_NGAP_TimeSyncAssistanceInfo__timeDistributionIndication;

/* Forward declarations */
struct NGAP_ProtocolExtensionContainer;

/* NGAP_TimeSyncAssistanceInfo */
typedef struct NGAP_TimeSyncAssistanceInfo {
	long	 timeDistributionIndication;
	long	*uUTimeSyncErrorBudget;	/* OPTIONAL */
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_TimeSyncAssistanceInfo_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_NGAP_timeDistributionIndication_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_TimeSyncAssistanceInfo;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_TimeSyncAssistanceInfo_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_TimeSyncAssistanceInfo_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_TimeSyncAssistanceInfo_H_ */
#include <asn_internal.h>
