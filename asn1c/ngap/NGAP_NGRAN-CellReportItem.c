/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_NGRAN-CellReportItem.h"

#include "NGAP_NGRAN-RadioResourceStatus.h"
#include "NGAP_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_NGAP_NGRAN_CellReportItem_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_NGRAN_CellReportItem, nGRAN_CGI),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
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
		"nGRAN-CGI"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_NGRAN_CellReportItem, nGRAN_CompositeAvailableCapacityGroup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_EUTRAN_CompositeAvailableCapacityGroup,
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
		"nGRAN-CompositeAvailableCapacityGroup"
		},
	{ ATF_POINTER, 4, offsetof(struct NGAP_NGRAN_CellReportItem, nGRAN_NumberOfActiveUEs),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_NGRAN_NumberOfActiveUEs,
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
		"nGRAN-NumberOfActiveUEs"
		},
	{ ATF_POINTER, 3, offsetof(struct NGAP_NGRAN_CellReportItem, nGRAN_NoofRRCConnections),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_NGRAN_NoofRRCConnections,
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
		"nGRAN-NoofRRCConnections"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_NGRAN_CellReportItem, nGRAN_RadioResourceStatus),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_NGRAN_RadioResourceStatus,
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
		"nGRAN-RadioResourceStatus"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_NGRAN_CellReportItem, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11905P138,
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
static const int asn_MAP_NGAP_NGRAN_CellReportItem_oms_1[] = { 2, 3, 4, 5 };
static const ber_tlv_tag_t asn_DEF_NGAP_NGRAN_CellReportItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_NGRAN_CellReportItem_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* nGRAN-CGI */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* nGRAN-CompositeAvailableCapacityGroup */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* nGRAN-NumberOfActiveUEs */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* nGRAN-NoofRRCConnections */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* nGRAN-RadioResourceStatus */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_NGRAN_CellReportItem_specs_1 = {
	sizeof(struct NGAP_NGRAN_CellReportItem),
	offsetof(struct NGAP_NGRAN_CellReportItem, _asn_ctx),
	asn_MAP_NGAP_NGRAN_CellReportItem_tag2el_1,
	6,	/* Count of tags in the map */
	asn_MAP_NGAP_NGRAN_CellReportItem_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	6,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_NGRAN_CellReportItem = {
	"NGRAN-CellReportItem",
	"NGRAN-CellReportItem",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_NGRAN_CellReportItem_tags_1,
	sizeof(asn_DEF_NGAP_NGRAN_CellReportItem_tags_1)
		/sizeof(asn_DEF_NGAP_NGRAN_CellReportItem_tags_1[0]), /* 1 */
	asn_DEF_NGAP_NGRAN_CellReportItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_NGRAN_CellReportItem_tags_1)
		/sizeof(asn_DEF_NGAP_NGRAN_CellReportItem_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_NGRAN_CellReportItem_1,
	6,	/* Elements count */
	&asn_SPC_NGAP_NGRAN_CellReportItem_specs_1	/* Additional specs */
};
