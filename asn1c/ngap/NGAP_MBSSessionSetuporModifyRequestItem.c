/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_MBSSessionSetuporModifyRequestItem.h"

#include "NGAP_AssociatedMBSQosFlowSetuporModifyRequestList.h"
#include "NGAP_QosFlowListWithCause.h"
#include "NGAP_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_NGAP_MBSSessionSetuporModifyRequestItem_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_MBSSessionSetuporModifyRequestItem, mBS_SessionID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_MBS_SessionID,
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
		"mBS-SessionID"
		},
	{ ATF_POINTER, 4, offsetof(struct NGAP_MBSSessionSetuporModifyRequestItem, mBS_AreaSessionID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_MBS_AreaSessionID,
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
		"mBS-AreaSessionID"
		},
	{ ATF_POINTER, 3, offsetof(struct NGAP_MBSSessionSetuporModifyRequestItem, associatedMBSQosFlowSetuporModifyRequestList),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_AssociatedMBSQosFlowSetuporModifyRequestList,
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
		"associatedMBSQosFlowSetuporModifyRequestList"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_MBSSessionSetuporModifyRequestItem, mBS_QosFlowToReleaseList),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_QosFlowListWithCause,
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
		"mBS-QosFlowToReleaseList"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_MBSSessionSetuporModifyRequestItem, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11905P170,
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
static const int asn_MAP_NGAP_MBSSessionSetuporModifyRequestItem_oms_1[] = { 1, 2, 3, 4 };
static const ber_tlv_tag_t asn_DEF_NGAP_MBSSessionSetuporModifyRequestItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_MBSSessionSetuporModifyRequestItem_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* mBS-SessionID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* mBS-AreaSessionID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* associatedMBSQosFlowSetuporModifyRequestList */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* mBS-QosFlowToReleaseList */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_MBSSessionSetuporModifyRequestItem_specs_1 = {
	sizeof(struct NGAP_MBSSessionSetuporModifyRequestItem),
	offsetof(struct NGAP_MBSSessionSetuporModifyRequestItem, _asn_ctx),
	asn_MAP_NGAP_MBSSessionSetuporModifyRequestItem_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_NGAP_MBSSessionSetuporModifyRequestItem_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	5,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_MBSSessionSetuporModifyRequestItem = {
	"MBSSessionSetuporModifyRequestItem",
	"MBSSessionSetuporModifyRequestItem",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_MBSSessionSetuporModifyRequestItem_tags_1,
	sizeof(asn_DEF_NGAP_MBSSessionSetuporModifyRequestItem_tags_1)
		/sizeof(asn_DEF_NGAP_MBSSessionSetuporModifyRequestItem_tags_1[0]), /* 1 */
	asn_DEF_NGAP_MBSSessionSetuporModifyRequestItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_MBSSessionSetuporModifyRequestItem_tags_1)
		/sizeof(asn_DEF_NGAP_MBSSessionSetuporModifyRequestItem_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_MBSSessionSetuporModifyRequestItem_1,
	5,	/* Elements count */
	&asn_SPC_NGAP_MBSSessionSetuporModifyRequestItem_specs_1	/* Additional specs */
};

