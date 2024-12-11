/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "../support/s1ap-r17.3.0/36413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_S1AP_DLCOUNT_PDCP_SNlength_H_
#define	_S1AP_DLCOUNT_PDCP_SNlength_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum S1AP_DLCOUNT_PDCP_SNlength_PR {
	S1AP_DLCOUNT_PDCP_SNlength_PR_NOTHING,	/* No components present */
	S1AP_DLCOUNT_PDCP_SNlength_PR_dLCOUNTValuePDCP_SNlength12,
	S1AP_DLCOUNT_PDCP_SNlength_PR_dLCOUNTValuePDCP_SNlength15,
	S1AP_DLCOUNT_PDCP_SNlength_PR_dLCOUNTValuePDCP_SNlength18
	/* Extensions may appear below */
	
} S1AP_DLCOUNT_PDCP_SNlength_PR;

/* Forward declarations */
struct S1AP_COUNTvalue;
struct S1AP_COUNTValueExtended;
struct S1AP_COUNTvaluePDCP_SNlength18;

/* S1AP_DLCOUNT-PDCP-SNlength */
typedef struct S1AP_DLCOUNT_PDCP_SNlength {
	S1AP_DLCOUNT_PDCP_SNlength_PR present;
	union S1AP_DLCOUNT_PDCP_SNlength_u {
		struct S1AP_COUNTvalue	*dLCOUNTValuePDCP_SNlength12;
		struct S1AP_COUNTValueExtended	*dLCOUNTValuePDCP_SNlength15;
		struct S1AP_COUNTvaluePDCP_SNlength18	*dLCOUNTValuePDCP_SNlength18;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_DLCOUNT_PDCP_SNlength_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_DLCOUNT_PDCP_SNlength;
extern asn_CHOICE_specifics_t asn_SPC_S1AP_DLCOUNT_PDCP_SNlength_specs_1;
extern asn_TYPE_member_t asn_MBR_S1AP_DLCOUNT_PDCP_SNlength_1[3];
extern asn_per_constraints_t asn_PER_type_S1AP_DLCOUNT_PDCP_SNlength_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_DLCOUNT_PDCP_SNlength_H_ */
#include <asn_internal.h>
