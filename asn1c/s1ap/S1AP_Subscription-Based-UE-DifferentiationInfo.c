/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "../support/s1ap-r17.3.0/36413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "S1AP_Subscription-Based-UE-DifferentiationInfo.h"

#include "S1AP_ScheduledCommunicationTime.h"
#include "S1AP_ProtocolExtensionContainer.h"
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_S1AP_periodicTime_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1L && value <= 3600L)) {
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
static asn_per_constraints_t asn_PER_type_S1AP_periodicCommunicationIndicator_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_S1AP_stationaryIndication_constr_8 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_S1AP_trafficProfile_constr_12 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_S1AP_batteryIndication_constr_17 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_S1AP_periodicTime_constr_6 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  12,  12,  1,  3600 }	/* (1..3600,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_S1AP_periodicCommunicationIndicator_value2enum_2[] = {
	{ 0,	12,	"periodically" },
	{ 1,	8,	"ondemand" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_S1AP_periodicCommunicationIndicator_enum2value_2[] = {
	1,	/* ondemand(1) */
	0	/* periodically(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_S1AP_periodicCommunicationIndicator_specs_2 = {
	asn_MAP_S1AP_periodicCommunicationIndicator_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_S1AP_periodicCommunicationIndicator_enum2value_2,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_S1AP_periodicCommunicationIndicator_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_S1AP_periodicCommunicationIndicator_2 = {
	"periodicCommunicationIndicator",
	"periodicCommunicationIndicator",
	&asn_OP_NativeEnumerated,
	asn_DEF_S1AP_periodicCommunicationIndicator_tags_2,
	sizeof(asn_DEF_S1AP_periodicCommunicationIndicator_tags_2)
		/sizeof(asn_DEF_S1AP_periodicCommunicationIndicator_tags_2[0]) - 1, /* 1 */
	asn_DEF_S1AP_periodicCommunicationIndicator_tags_2,	/* Same as above */
	sizeof(asn_DEF_S1AP_periodicCommunicationIndicator_tags_2)
		/sizeof(asn_DEF_S1AP_periodicCommunicationIndicator_tags_2[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_S1AP_periodicCommunicationIndicator_constr_2,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_S1AP_periodicCommunicationIndicator_specs_2	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_S1AP_stationaryIndication_value2enum_8[] = {
	{ 0,	10,	"stationary" },
	{ 1,	6,	"mobile" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_S1AP_stationaryIndication_enum2value_8[] = {
	1,	/* mobile(1) */
	0	/* stationary(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_S1AP_stationaryIndication_specs_8 = {
	asn_MAP_S1AP_stationaryIndication_value2enum_8,	/* "tag" => N; sorted by tag */
	asn_MAP_S1AP_stationaryIndication_enum2value_8,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_S1AP_stationaryIndication_tags_8[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_S1AP_stationaryIndication_8 = {
	"stationaryIndication",
	"stationaryIndication",
	&asn_OP_NativeEnumerated,
	asn_DEF_S1AP_stationaryIndication_tags_8,
	sizeof(asn_DEF_S1AP_stationaryIndication_tags_8)
		/sizeof(asn_DEF_S1AP_stationaryIndication_tags_8[0]) - 1, /* 1 */
	asn_DEF_S1AP_stationaryIndication_tags_8,	/* Same as above */
	sizeof(asn_DEF_S1AP_stationaryIndication_tags_8)
		/sizeof(asn_DEF_S1AP_stationaryIndication_tags_8[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_S1AP_stationaryIndication_constr_8,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_S1AP_stationaryIndication_specs_8	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_S1AP_trafficProfile_value2enum_12[] = {
	{ 0,	13,	"single-packet" },
	{ 1,	12,	"dual-packets" },
	{ 2,	16,	"multiple-packets" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_S1AP_trafficProfile_enum2value_12[] = {
	1,	/* dual-packets(1) */
	2,	/* multiple-packets(2) */
	0	/* single-packet(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_S1AP_trafficProfile_specs_12 = {
	asn_MAP_S1AP_trafficProfile_value2enum_12,	/* "tag" => N; sorted by tag */
	asn_MAP_S1AP_trafficProfile_enum2value_12,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_S1AP_trafficProfile_tags_12[] = {
	(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_S1AP_trafficProfile_12 = {
	"trafficProfile",
	"trafficProfile",
	&asn_OP_NativeEnumerated,
	asn_DEF_S1AP_trafficProfile_tags_12,
	sizeof(asn_DEF_S1AP_trafficProfile_tags_12)
		/sizeof(asn_DEF_S1AP_trafficProfile_tags_12[0]) - 1, /* 1 */
	asn_DEF_S1AP_trafficProfile_tags_12,	/* Same as above */
	sizeof(asn_DEF_S1AP_trafficProfile_tags_12)
		/sizeof(asn_DEF_S1AP_trafficProfile_tags_12[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_S1AP_trafficProfile_constr_12,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_S1AP_trafficProfile_specs_12	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_S1AP_batteryIndication_value2enum_17[] = {
	{ 0,	15,	"battery-powered" },
	{ 1,	47,	"battery-powered-not-rechargeable-or-replaceable" },
	{ 2,	19,	"not-battery-powered" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_S1AP_batteryIndication_enum2value_17[] = {
	0,	/* battery-powered(0) */
	1,	/* battery-powered-not-rechargeable-or-replaceable(1) */
	2	/* not-battery-powered(2) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_S1AP_batteryIndication_specs_17 = {
	asn_MAP_S1AP_batteryIndication_value2enum_17,	/* "tag" => N; sorted by tag */
	asn_MAP_S1AP_batteryIndication_enum2value_17,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_S1AP_batteryIndication_tags_17[] = {
	(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_S1AP_batteryIndication_17 = {
	"batteryIndication",
	"batteryIndication",
	&asn_OP_NativeEnumerated,
	asn_DEF_S1AP_batteryIndication_tags_17,
	sizeof(asn_DEF_S1AP_batteryIndication_tags_17)
		/sizeof(asn_DEF_S1AP_batteryIndication_tags_17[0]) - 1, /* 1 */
	asn_DEF_S1AP_batteryIndication_tags_17,	/* Same as above */
	sizeof(asn_DEF_S1AP_batteryIndication_tags_17)
		/sizeof(asn_DEF_S1AP_batteryIndication_tags_17[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_S1AP_batteryIndication_constr_17,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_S1AP_batteryIndication_specs_17	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_S1AP_Subscription_Based_UE_DifferentiationInfo_1[] = {
	{ ATF_POINTER, 7, offsetof(struct S1AP_Subscription_Based_UE_DifferentiationInfo, periodicCommunicationIndicator),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_periodicCommunicationIndicator_2,
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
		"periodicCommunicationIndicator"
		},
	{ ATF_POINTER, 6, offsetof(struct S1AP_Subscription_Based_UE_DifferentiationInfo, periodicTime),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_S1AP_periodicTime_constr_6,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_S1AP_periodicTime_constraint_1
		},
		0, 0, /* No default value */
		"periodicTime"
		},
	{ ATF_POINTER, 5, offsetof(struct S1AP_Subscription_Based_UE_DifferentiationInfo, scheduledCommunicationTime),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_ScheduledCommunicationTime,
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
		"scheduledCommunicationTime"
		},
	{ ATF_POINTER, 4, offsetof(struct S1AP_Subscription_Based_UE_DifferentiationInfo, stationaryIndication),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_stationaryIndication_8,
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
		"stationaryIndication"
		},
	{ ATF_POINTER, 3, offsetof(struct S1AP_Subscription_Based_UE_DifferentiationInfo, trafficProfile),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_trafficProfile_12,
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
		"trafficProfile"
		},
	{ ATF_POINTER, 2, offsetof(struct S1AP_Subscription_Based_UE_DifferentiationInfo, batteryIndication),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_batteryIndication_17,
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
		"batteryIndication"
		},
	{ ATF_POINTER, 1, offsetof(struct S1AP_Subscription_Based_UE_DifferentiationInfo, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_ProtocolExtensionContainer_8194P136,
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
static const int asn_MAP_S1AP_Subscription_Based_UE_DifferentiationInfo_oms_1[] = { 0, 1, 2, 3, 4, 5, 6 };
static const ber_tlv_tag_t asn_DEF_S1AP_Subscription_Based_UE_DifferentiationInfo_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_S1AP_Subscription_Based_UE_DifferentiationInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* periodicCommunicationIndicator */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* periodicTime */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* scheduledCommunicationTime */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* stationaryIndication */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* trafficProfile */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* batteryIndication */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_S1AP_Subscription_Based_UE_DifferentiationInfo_specs_1 = {
	sizeof(struct S1AP_Subscription_Based_UE_DifferentiationInfo),
	offsetof(struct S1AP_Subscription_Based_UE_DifferentiationInfo, _asn_ctx),
	asn_MAP_S1AP_Subscription_Based_UE_DifferentiationInfo_tag2el_1,
	7,	/* Count of tags in the map */
	asn_MAP_S1AP_Subscription_Based_UE_DifferentiationInfo_oms_1,	/* Optional members */
	7, 0,	/* Root/Additions */
	7,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_S1AP_Subscription_Based_UE_DifferentiationInfo = {
	"Subscription-Based-UE-DifferentiationInfo",
	"Subscription-Based-UE-DifferentiationInfo",
	&asn_OP_SEQUENCE,
	asn_DEF_S1AP_Subscription_Based_UE_DifferentiationInfo_tags_1,
	sizeof(asn_DEF_S1AP_Subscription_Based_UE_DifferentiationInfo_tags_1)
		/sizeof(asn_DEF_S1AP_Subscription_Based_UE_DifferentiationInfo_tags_1[0]), /* 1 */
	asn_DEF_S1AP_Subscription_Based_UE_DifferentiationInfo_tags_1,	/* Same as above */
	sizeof(asn_DEF_S1AP_Subscription_Based_UE_DifferentiationInfo_tags_1)
		/sizeof(asn_DEF_S1AP_Subscription_Based_UE_DifferentiationInfo_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_S1AP_Subscription_Based_UE_DifferentiationInfo_1,
	7,	/* Elements count */
	&asn_SPC_S1AP_Subscription_Based_UE_DifferentiationInfo_specs_1	/* Additional specs */
};

