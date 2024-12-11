/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "../support/s1ap-r17.3.0/36413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "S1AP_LastVisitedGERANCellInformation.h"

#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_S1AP_LastVisitedGERANCellInformation_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_S1AP_LastVisitedGERANCellInformation_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct S1AP_LastVisitedGERANCellInformation, choice.undefined),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"undefined"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_S1AP_LastVisitedGERANCellInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* undefined */
};
asn_CHOICE_specifics_t asn_SPC_S1AP_LastVisitedGERANCellInformation_specs_1 = {
	sizeof(struct S1AP_LastVisitedGERANCellInformation),
	offsetof(struct S1AP_LastVisitedGERANCellInformation, _asn_ctx),
	offsetof(struct S1AP_LastVisitedGERANCellInformation, present),
	sizeof(((struct S1AP_LastVisitedGERANCellInformation *)0)->present),
	asn_MAP_S1AP_LastVisitedGERANCellInformation_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0,
	1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_S1AP_LastVisitedGERANCellInformation = {
	"LastVisitedGERANCellInformation",
	"LastVisitedGERANCellInformation",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_S1AP_LastVisitedGERANCellInformation_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		CHOICE_constraint
	},
	asn_MBR_S1AP_LastVisitedGERANCellInformation_1,
	1,	/* Elements count */
	&asn_SPC_S1AP_LastVisitedGERANCellInformation_specs_1	/* Additional specs */
};

