/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_MRB_ProgressInformation_H_
#define	_NGAP_MRB_ProgressInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_MRB_ProgressInformation_PR {
	NGAP_MRB_ProgressInformation_PR_NOTHING,	/* No components present */
	NGAP_MRB_ProgressInformation_PR_pDCP_SN_Length12,
	NGAP_MRB_ProgressInformation_PR_pDCP_SN_Length18,
	NGAP_MRB_ProgressInformation_PR_choice_Extensions
} NGAP_MRB_ProgressInformation_PR;

/* Forward declarations */
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_MRB-ProgressInformation */
typedef struct NGAP_MRB_ProgressInformation {
	NGAP_MRB_ProgressInformation_PR present;
	union NGAP_MRB_ProgressInformation_u {
		long	 pDCP_SN_Length12;
		long	 pDCP_SN_Length18;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_MRB_ProgressInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_MRB_ProgressInformation;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_MRB_ProgressInformation_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_MRB_ProgressInformation_1[3];
extern asn_per_constraints_t asn_PER_type_NGAP_MRB_ProgressInformation_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_MRB_ProgressInformation_H_ */
#include <asn_internal.h>
