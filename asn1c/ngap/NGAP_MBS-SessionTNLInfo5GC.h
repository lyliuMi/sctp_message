/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_MBS_SessionTNLInfo5GC_H_
#define	_NGAP_MBS_SessionTNLInfo5GC_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_MBS_SessionTNLInfo5GC_PR {
	NGAP_MBS_SessionTNLInfo5GC_PR_NOTHING,	/* No components present */
	NGAP_MBS_SessionTNLInfo5GC_PR_locationindependent,
	NGAP_MBS_SessionTNLInfo5GC_PR_locationdependent,
	NGAP_MBS_SessionTNLInfo5GC_PR_choice_Extensions
} NGAP_MBS_SessionTNLInfo5GC_PR;

/* Forward declarations */
struct NGAP_SharedNGU_MulticastTNLInformation;
struct NGAP_MBS_SessionTNLInfo5GCList;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_MBS-SessionTNLInfo5GC */
typedef struct NGAP_MBS_SessionTNLInfo5GC {
	NGAP_MBS_SessionTNLInfo5GC_PR present;
	union NGAP_MBS_SessionTNLInfo5GC_u {
		struct NGAP_SharedNGU_MulticastTNLInformation	*locationindependent;
		struct NGAP_MBS_SessionTNLInfo5GCList	*locationdependent;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_MBS_SessionTNLInfo5GC_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_MBS_SessionTNLInfo5GC;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_MBS_SessionTNLInfo5GC_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_MBS_SessionTNLInfo5GC_1[3];
extern asn_per_constraints_t asn_PER_type_NGAP_MBS_SessionTNLInfo5GC_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_MBS_SessionTNLInfo5GC_H_ */
#include <asn_internal.h>
