/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "../support/s1ap-r17.3.0/36413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_S1AP_Subscription_Based_UE_DifferentiationInfo_H_
#define	_S1AP_Subscription_Based_UE_DifferentiationInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum S1AP_Subscription_Based_UE_DifferentiationInfo__periodicCommunicationIndicator {
	S1AP_Subscription_Based_UE_DifferentiationInfo__periodicCommunicationIndicator_periodically	= 0,
	S1AP_Subscription_Based_UE_DifferentiationInfo__periodicCommunicationIndicator_ondemand	= 1
	/*
	 * Enumeration is extensible
	 */
} e_S1AP_Subscription_Based_UE_DifferentiationInfo__periodicCommunicationIndicator;
typedef enum S1AP_Subscription_Based_UE_DifferentiationInfo__stationaryIndication {
	S1AP_Subscription_Based_UE_DifferentiationInfo__stationaryIndication_stationary	= 0,
	S1AP_Subscription_Based_UE_DifferentiationInfo__stationaryIndication_mobile	= 1
	/*
	 * Enumeration is extensible
	 */
} e_S1AP_Subscription_Based_UE_DifferentiationInfo__stationaryIndication;
typedef enum S1AP_Subscription_Based_UE_DifferentiationInfo__trafficProfile {
	S1AP_Subscription_Based_UE_DifferentiationInfo__trafficProfile_single_packet	= 0,
	S1AP_Subscription_Based_UE_DifferentiationInfo__trafficProfile_dual_packets	= 1,
	S1AP_Subscription_Based_UE_DifferentiationInfo__trafficProfile_multiple_packets	= 2
	/*
	 * Enumeration is extensible
	 */
} e_S1AP_Subscription_Based_UE_DifferentiationInfo__trafficProfile;
typedef enum S1AP_Subscription_Based_UE_DifferentiationInfo__batteryIndication {
	S1AP_Subscription_Based_UE_DifferentiationInfo__batteryIndication_battery_powered	= 0,
	S1AP_Subscription_Based_UE_DifferentiationInfo__batteryIndication_battery_powered_not_rechargeable_or_replaceable	= 1,
	S1AP_Subscription_Based_UE_DifferentiationInfo__batteryIndication_not_battery_powered	= 2
	/*
	 * Enumeration is extensible
	 */
} e_S1AP_Subscription_Based_UE_DifferentiationInfo__batteryIndication;

/* Forward declarations */
struct S1AP_ScheduledCommunicationTime;
struct S1AP_ProtocolExtensionContainer;

/* S1AP_Subscription-Based-UE-DifferentiationInfo */
typedef struct S1AP_Subscription_Based_UE_DifferentiationInfo {
	long	*periodicCommunicationIndicator;	/* OPTIONAL */
	long	*periodicTime;	/* OPTIONAL */
	struct S1AP_ScheduledCommunicationTime	*scheduledCommunicationTime;	/* OPTIONAL */
	long	*stationaryIndication;	/* OPTIONAL */
	long	*trafficProfile;	/* OPTIONAL */
	long	*batteryIndication;	/* OPTIONAL */
	struct S1AP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_Subscription_Based_UE_DifferentiationInfo_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_S1AP_periodicCommunicationIndicator_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_S1AP_stationaryIndication_8;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_S1AP_trafficProfile_12;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_S1AP_batteryIndication_17;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_Subscription_Based_UE_DifferentiationInfo;
extern asn_SEQUENCE_specifics_t asn_SPC_S1AP_Subscription_Based_UE_DifferentiationInfo_specs_1;
extern asn_TYPE_member_t asn_MBR_S1AP_Subscription_Based_UE_DifferentiationInfo_1[7];

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_Subscription_Based_UE_DifferentiationInfo_H_ */
#include <asn_internal.h>
