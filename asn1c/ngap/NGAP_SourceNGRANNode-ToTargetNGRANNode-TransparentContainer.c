/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_SourceNGRANNode-ToTargetNGRANNode-TransparentContainer.h"

#include "NGAP_PDUSessionResourceInformationList.h"
#include "NGAP_E-RABInformationList.h"
#include "NGAP_ProtocolExtensionContainer.h"
static asn_TYPE_member_t asn_MBR_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer, rRCContainer),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_RRCContainer,
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
		"rRCContainer"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer, pDUSessionResourceInformationList),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_PDUSessionResourceInformationList,
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
		"pDUSessionResourceInformationList"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer, e_RABInformationList),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_E_RABInformationList,
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
		"e-RABInformationList"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer, targetCell_ID),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NGAP_NGRAN_CGI,
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
		"targetCell-ID"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer, indexToRFSP),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_IndexToRFSP,
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
		"indexToRFSP"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer, uEHistoryInformation),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_UEHistoryInformation,
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
		"uEHistoryInformation"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11905P312,
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
static const int asn_MAP_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_oms_1[] = { 1, 2, 4, 6 };
static const ber_tlv_tag_t asn_DEF_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* rRCContainer */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* pDUSessionResourceInformationList */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* e-RABInformationList */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* targetCell-ID */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* indexToRFSP */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* uEHistoryInformation */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* iE-Extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_specs_1 = {
	sizeof(struct NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer),
	offsetof(struct NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer, _asn_ctx),
	asn_MAP_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_tag2el_1,
	7,	/* Count of tags in the map */
	asn_MAP_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	7,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer = {
	"SourceNGRANNode-ToTargetNGRANNode-TransparentContainer",
	"SourceNGRANNode-ToTargetNGRANNode-TransparentContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_tags_1,
	sizeof(asn_DEF_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_tags_1)
		/sizeof(asn_DEF_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_tags_1[0]), /* 1 */
	asn_DEF_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_tags_1)
		/sizeof(asn_DEF_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_1,
	7,	/* Elements count */
	&asn_SPC_NGAP_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_specs_1	/* Additional specs */
};

