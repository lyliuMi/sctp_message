/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r17.3.0/38413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#include "NGAP_PDUSessionResourceSetupItemHOReq.h"

#include "NGAP_ProtocolExtensionContainer.h"
static int
memb_NGAP_handoverRequestTransfer_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		(void)st; /* Unused variable */
		/* Nothing is here. See below */
	}
	
	return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
}

#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_NGAP_handoverRequestTransfer_constr_4 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_SEMI_CONSTRAINED,	-1, -1,  0,  0 }	/* (SIZE(0..MAX)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_NGAP_PDUSessionResourceSetupItemHOReq_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_PDUSessionResourceSetupItemHOReq, pDUSessionID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_PDUSessionID,
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
		"pDUSessionID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_PDUSessionResourceSetupItemHOReq, s_NSSAI),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_S_NSSAI,
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
		"s-NSSAI"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_PDUSessionResourceSetupItemHOReq, handoverRequestTransfer),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_NGAP_handoverRequestTransfer_constr_4,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_NGAP_handoverRequestTransfer_constraint_1
		},
		0, 0, /* No default value */
		"handoverRequestTransfer"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_PDUSessionResourceSetupItemHOReq, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_11905P251,
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
static const int asn_MAP_NGAP_PDUSessionResourceSetupItemHOReq_oms_1[] = { 3 };
static const ber_tlv_tag_t asn_DEF_NGAP_PDUSessionResourceSetupItemHOReq_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_PDUSessionResourceSetupItemHOReq_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pDUSessionID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* s-NSSAI */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* handoverRequestTransfer */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_PDUSessionResourceSetupItemHOReq_specs_1 = {
	sizeof(struct NGAP_PDUSessionResourceSetupItemHOReq),
	offsetof(struct NGAP_PDUSessionResourceSetupItemHOReq, _asn_ctx),
	asn_MAP_NGAP_PDUSessionResourceSetupItemHOReq_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_NGAP_PDUSessionResourceSetupItemHOReq_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_PDUSessionResourceSetupItemHOReq = {
	"PDUSessionResourceSetupItemHOReq",
	"PDUSessionResourceSetupItemHOReq",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_PDUSessionResourceSetupItemHOReq_tags_1,
	sizeof(asn_DEF_NGAP_PDUSessionResourceSetupItemHOReq_tags_1)
		/sizeof(asn_DEF_NGAP_PDUSessionResourceSetupItemHOReq_tags_1[0]), /* 1 */
	asn_DEF_NGAP_PDUSessionResourceSetupItemHOReq_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_PDUSessionResourceSetupItemHOReq_tags_1)
		/sizeof(asn_DEF_NGAP_PDUSessionResourceSetupItemHOReq_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_PDUSessionResourceSetupItemHOReq_1,
	4,	/* Elements count */
	&asn_SPC_NGAP_PDUSessionResourceSetupItemHOReq_specs_1	/* Additional specs */
};

