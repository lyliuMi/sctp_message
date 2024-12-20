/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "../support/s1ap-r17.3.0/36413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "S1AP_DLCOUNT-PDCP-SNlength.h"

#include "S1AP_COUNTvalue.h"
#include "S1AP_COUNTValueExtended.h"
#include "S1AP_COUNTvaluePDCP-SNlength18.h"
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_S1AP_DLCOUNT_PDCP_SNlength_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_S1AP_DLCOUNT_PDCP_SNlength_1[] = {
	{ ATF_POINTER, 0, offsetof(struct S1AP_DLCOUNT_PDCP_SNlength, choice.dLCOUNTValuePDCP_SNlength12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_COUNTvalue,
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
		"dLCOUNTValuePDCP-SNlength12"
		},
	{ ATF_POINTER, 0, offsetof(struct S1AP_DLCOUNT_PDCP_SNlength, choice.dLCOUNTValuePDCP_SNlength15),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_COUNTValueExtended,
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
		"dLCOUNTValuePDCP-SNlength15"
		},
	{ ATF_POINTER, 0, offsetof(struct S1AP_DLCOUNT_PDCP_SNlength, choice.dLCOUNTValuePDCP_SNlength18),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_COUNTvaluePDCP_SNlength18,
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
		"dLCOUNTValuePDCP-SNlength18"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_S1AP_DLCOUNT_PDCP_SNlength_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* dLCOUNTValuePDCP-SNlength12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* dLCOUNTValuePDCP-SNlength15 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* dLCOUNTValuePDCP-SNlength18 */
};
asn_CHOICE_specifics_t asn_SPC_S1AP_DLCOUNT_PDCP_SNlength_specs_1 = {
	sizeof(struct S1AP_DLCOUNT_PDCP_SNlength),
	offsetof(struct S1AP_DLCOUNT_PDCP_SNlength, _asn_ctx),
	offsetof(struct S1AP_DLCOUNT_PDCP_SNlength, present),
	sizeof(((struct S1AP_DLCOUNT_PDCP_SNlength *)0)->present),
	asn_MAP_S1AP_DLCOUNT_PDCP_SNlength_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0,
	3	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_S1AP_DLCOUNT_PDCP_SNlength = {
	"DLCOUNT-PDCP-SNlength",
	"DLCOUNT-PDCP-SNlength",
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
		&asn_PER_type_S1AP_DLCOUNT_PDCP_SNlength_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		CHOICE_constraint
	},
	asn_MBR_S1AP_DLCOUNT_PDCP_SNlength_1,
	3,	/* Elements count */
	&asn_SPC_S1AP_DLCOUNT_PDCP_SNlength_specs_1	/* Additional specs */
};

