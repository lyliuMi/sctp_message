/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_UnavailableGUAMIItem.h"

#include "NGAP_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_NGAP_UnavailableGUAMIItem_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_UnavailableGUAMIItem, gUAMI),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_GUAMI,
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
		"gUAMI"
		},
	{ ATF_POINTER, 3, offsetof(struct NGAP_UnavailableGUAMIItem, timerApproachForGUAMIRemoval),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_TimerApproachForGUAMIRemoval,
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
		"timerApproachForGUAMIRemoval"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_UnavailableGUAMIItem, backupAMFName),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_AMFName,
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
		"backupAMFName"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_UnavailableGUAMIItem, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11905P356,
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
		"iE-Extensions"
		},
};
static const int asn_MAP_NGAP_UnavailableGUAMIItem_oms_1[] = { 1, 2, 3 };
static const ber_tlv_tag_t asn_DEF_NGAP_UnavailableGUAMIItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_UnavailableGUAMIItem_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* gUAMI */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* timerApproachForGUAMIRemoval */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* backupAMFName */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_UnavailableGUAMIItem_specs_1 = {
	sizeof(struct NGAP_UnavailableGUAMIItem),
	offsetof(struct NGAP_UnavailableGUAMIItem, _asn_ctx),
	asn_MAP_NGAP_UnavailableGUAMIItem_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_NGAP_UnavailableGUAMIItem_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_UnavailableGUAMIItem = {
	"UnavailableGUAMIItem",
	"UnavailableGUAMIItem",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_UnavailableGUAMIItem_tags_1,
	sizeof(asn_DEF_NGAP_UnavailableGUAMIItem_tags_1)
		/sizeof(asn_DEF_NGAP_UnavailableGUAMIItem_tags_1[0]), /* 1 */
	asn_DEF_NGAP_UnavailableGUAMIItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_UnavailableGUAMIItem_tags_1)
		/sizeof(asn_DEF_NGAP_UnavailableGUAMIItem_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_UnavailableGUAMIItem_1,
	4,	/* Elements count */
	&asn_SPC_NGAP_UnavailableGUAMIItem_specs_1	/* Additional specs */
};

