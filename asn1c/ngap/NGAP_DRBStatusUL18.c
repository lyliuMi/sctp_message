/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_DRBStatusUL18.h"

#include "NGAP_ProtocolExtensionContainer.h"
static int
memb_NGAP_receiveStatusOfUL_PDCP_SDUs_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size >= 1UL && size <= 131072UL)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_NGAP_receiveStatusOfUL_PDCP_SDUs_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 17, -1,  1,  131072 }	/* (SIZE(1..131072)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_NGAP_DRBStatusUL18_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_DRBStatusUL18, uL_COUNTValue),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_COUNTValueForPDCP_SN18,
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
		"uL-COUNTValue"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_DRBStatusUL18, receiveStatusOfUL_PDCP_SDUs),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_NGAP_receiveStatusOfUL_PDCP_SDUs_constr_3,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_NGAP_receiveStatusOfUL_PDCP_SDUs_constraint_1
		},
		0, 0, /* No default value */
		"receiveStatusOfUL-PDCP-SDUs"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_DRBStatusUL18, iE_Extension),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11905P63,
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
		"iE-Extension"
		},
};
static const int asn_MAP_NGAP_DRBStatusUL18_oms_1[] = { 1, 2 };
static const ber_tlv_tag_t asn_DEF_NGAP_DRBStatusUL18_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_DRBStatusUL18_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* uL-COUNTValue */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* receiveStatusOfUL-PDCP-SDUs */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extension */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_DRBStatusUL18_specs_1 = {
	sizeof(struct NGAP_DRBStatusUL18),
	offsetof(struct NGAP_DRBStatusUL18, _asn_ctx),
	asn_MAP_NGAP_DRBStatusUL18_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_NGAP_DRBStatusUL18_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_DRBStatusUL18 = {
	"DRBStatusUL18",
	"DRBStatusUL18",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_DRBStatusUL18_tags_1,
	sizeof(asn_DEF_NGAP_DRBStatusUL18_tags_1)
		/sizeof(asn_DEF_NGAP_DRBStatusUL18_tags_1[0]), /* 1 */
	asn_DEF_NGAP_DRBStatusUL18_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_DRBStatusUL18_tags_1)
		/sizeof(asn_DEF_NGAP_DRBStatusUL18_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_DRBStatusUL18_1,
	3,	/* Elements count */
	&asn_SPC_NGAP_DRBStatusUL18_specs_1	/* Additional specs */
};

