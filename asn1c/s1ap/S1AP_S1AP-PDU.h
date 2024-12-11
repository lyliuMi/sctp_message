/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-PDU-Descriptions"
 * 	found in "../support/s1ap-r17.3.0/36413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_S1AP_S1AP_PDU_H_
#define	_S1AP_S1AP_PDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum S1AP_S1AP_PDU_PR {
	S1AP_S1AP_PDU_PR_NOTHING,	/* No components present */
	S1AP_S1AP_PDU_PR_initiatingMessage,
	S1AP_S1AP_PDU_PR_successfulOutcome,
	S1AP_S1AP_PDU_PR_unsuccessfulOutcome
	/* Extensions may appear below */
	
} S1AP_S1AP_PDU_PR;

/* Forward declarations */
struct S1AP_InitiatingMessage;
struct S1AP_SuccessfulOutcome;
struct S1AP_UnsuccessfulOutcome;

/* S1AP_S1AP-PDU */
typedef struct S1AP_S1AP_PDU {
	S1AP_S1AP_PDU_PR present;
	union S1AP_S1AP_PDU_u {
		struct S1AP_InitiatingMessage	*initiatingMessage;
		struct S1AP_SuccessfulOutcome	*successfulOutcome;
		struct S1AP_UnsuccessfulOutcome	*unsuccessfulOutcome;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_S1AP_PDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_S1AP_PDU;

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_S1AP_PDU_H_ */
#include <asn_internal.h>
