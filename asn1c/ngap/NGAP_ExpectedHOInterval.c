/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_ExpectedHOInterval.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_NGAP_ExpectedHOInterval_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  6 }	/* (0..6,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_NGAP_ExpectedHOInterval_value2enum_1[] = {
	{ 0,	5,	"sec15" },
	{ 1,	5,	"sec30" },
	{ 2,	5,	"sec60" },
	{ 3,	5,	"sec90" },
	{ 4,	6,	"sec120" },
	{ 5,	6,	"sec180" },
	{ 6,	9,	"long-time" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NGAP_ExpectedHOInterval_enum2value_1[] = {
	6,	/* long-time(6) */
	4,	/* sec120(4) */
	0,	/* sec15(0) */
	5,	/* sec180(5) */
	1,	/* sec30(1) */
	2,	/* sec60(2) */
	3	/* sec90(3) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_NGAP_ExpectedHOInterval_specs_1 = {
	asn_MAP_NGAP_ExpectedHOInterval_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_NGAP_ExpectedHOInterval_enum2value_1,	/* N => "tag"; sorted by N */
	7,	/* Number of elements in the maps */
	8,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NGAP_ExpectedHOInterval_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_NGAP_ExpectedHOInterval = {
	"ExpectedHOInterval",
	"ExpectedHOInterval",
	&asn_OP_NativeEnumerated,
	asn_DEF_NGAP_ExpectedHOInterval_tags_1,
	sizeof(asn_DEF_NGAP_ExpectedHOInterval_tags_1)
		/sizeof(asn_DEF_NGAP_ExpectedHOInterval_tags_1[0]), /* 1 */
	asn_DEF_NGAP_ExpectedHOInterval_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_ExpectedHOInterval_tags_1)
		/sizeof(asn_DEF_NGAP_ExpectedHOInterval_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NGAP_ExpectedHOInterval_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NGAP_ExpectedHOInterval_specs_1	/* Additional specs */
};

