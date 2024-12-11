/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_WLANMeasurementConfiguration.h"

#include "NGAP_WLANMeasConfigNameList.h"
#include "NGAP_ProtocolExtensionContainer.h"
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_NGAP_wlan_rssi_constr_4 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_NGAP_wlan_rtt_constr_7 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_NGAP_wlan_rssi_value2enum_4[] = {
	{ 0,	4,	"true" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NGAP_wlan_rssi_enum2value_4[] = {
	0	/* true(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_NGAP_wlan_rssi_specs_4 = {
	asn_MAP_NGAP_wlan_rssi_value2enum_4,	/* "tag" => N; sorted by tag */
	asn_MAP_NGAP_wlan_rssi_enum2value_4,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	2,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NGAP_wlan_rssi_tags_4[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_NGAP_wlan_rssi_4 = {
	"wlan-rssi",
	"wlan-rssi",
	&asn_OP_NativeEnumerated,
	asn_DEF_NGAP_wlan_rssi_tags_4,
	sizeof(asn_DEF_NGAP_wlan_rssi_tags_4)
		/sizeof(asn_DEF_NGAP_wlan_rssi_tags_4[0]) - 1, /* 1 */
	asn_DEF_NGAP_wlan_rssi_tags_4,	/* Same as above */
	sizeof(asn_DEF_NGAP_wlan_rssi_tags_4)
		/sizeof(asn_DEF_NGAP_wlan_rssi_tags_4[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NGAP_wlan_rssi_constr_4,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NGAP_wlan_rssi_specs_4	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_NGAP_wlan_rtt_value2enum_7[] = {
	{ 0,	4,	"true" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NGAP_wlan_rtt_enum2value_7[] = {
	0	/* true(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_NGAP_wlan_rtt_specs_7 = {
	asn_MAP_NGAP_wlan_rtt_value2enum_7,	/* "tag" => N; sorted by tag */
	asn_MAP_NGAP_wlan_rtt_enum2value_7,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	2,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NGAP_wlan_rtt_tags_7[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_NGAP_wlan_rtt_7 = {
	"wlan-rtt",
	"wlan-rtt",
	&asn_OP_NativeEnumerated,
	asn_DEF_NGAP_wlan_rtt_tags_7,
	sizeof(asn_DEF_NGAP_wlan_rtt_tags_7)
		/sizeof(asn_DEF_NGAP_wlan_rtt_tags_7[0]) - 1, /* 1 */
	asn_DEF_NGAP_wlan_rtt_tags_7,	/* Same as above */
	sizeof(asn_DEF_NGAP_wlan_rtt_tags_7)
		/sizeof(asn_DEF_NGAP_wlan_rtt_tags_7[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_NGAP_wlan_rtt_constr_7,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NGAP_wlan_rtt_specs_7	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_NGAP_WLANMeasurementConfiguration_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_WLANMeasurementConfiguration, wlanMeasConfig),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_WLANMeasConfig,
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
		"wlanMeasConfig"
		},
	{ ATF_POINTER, 4, offsetof(struct NGAP_WLANMeasurementConfiguration, wlanMeasConfigNameList),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_WLANMeasConfigNameList,
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
		"wlanMeasConfigNameList"
		},
	{ ATF_POINTER, 3, offsetof(struct NGAP_WLANMeasurementConfiguration, wlan_rssi),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_wlan_rssi_4,
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
		"wlan-rssi"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_WLANMeasurementConfiguration, wlan_rtt),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_wlan_rtt_7,
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
		"wlan-rtt"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_WLANMeasurementConfiguration, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11905P366,
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
static const int asn_MAP_NGAP_WLANMeasurementConfiguration_oms_1[] = { 1, 2, 3, 4 };
static const ber_tlv_tag_t asn_DEF_NGAP_WLANMeasurementConfiguration_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_WLANMeasurementConfiguration_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* wlanMeasConfig */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* wlanMeasConfigNameList */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* wlan-rssi */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* wlan-rtt */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_WLANMeasurementConfiguration_specs_1 = {
	sizeof(struct NGAP_WLANMeasurementConfiguration),
	offsetof(struct NGAP_WLANMeasurementConfiguration, _asn_ctx),
	asn_MAP_NGAP_WLANMeasurementConfiguration_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_NGAP_WLANMeasurementConfiguration_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	5,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_WLANMeasurementConfiguration = {
	"WLANMeasurementConfiguration",
	"WLANMeasurementConfiguration",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_WLANMeasurementConfiguration_tags_1,
	sizeof(asn_DEF_NGAP_WLANMeasurementConfiguration_tags_1)
		/sizeof(asn_DEF_NGAP_WLANMeasurementConfiguration_tags_1[0]), /* 1 */
	asn_DEF_NGAP_WLANMeasurementConfiguration_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_WLANMeasurementConfiguration_tags_1)
		/sizeof(asn_DEF_NGAP_WLANMeasurementConfiguration_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_WLANMeasurementConfiguration_1,
	5,	/* Elements count */
	&asn_SPC_NGAP_WLANMeasurementConfiguration_specs_1	/* Additional specs */
};

