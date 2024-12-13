#include "s1ap_build.h"
#include "mempool.h"
#include "list.h"
#include "context.h"
#include "pkbuf.h"
#include "message.h"
#include <string.h>

const char buf[32] = 
{
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
    0x01, 0x02
};



void s1ap_uint32_to_ENB_ID(
    S1AP_ENB_ID_PR present, uint32_t enb_id, S1AP_ENB_ID_t *eNB_ID)
{
    assert(eNB_ID);

    eNB_ID->present = present;
    if (present == S1AP_ENB_ID_PR_macroENB_ID) {
        BIT_STRING_t *bit_string = &eNB_ID->choice.macroENB_ID;
        assert(bit_string);

        bit_string->size = 3;
        bit_string->buf = CALLOC(bit_string->size, sizeof(uint8_t));

        bit_string->buf[0] = enb_id >> 12;
        bit_string->buf[1] = enb_id >> 4;
        bit_string->buf[2] = (enb_id & 0xf) << 4;

        bit_string->bits_unused = 4;
    } else if (present == S1AP_ENB_ID_PR_homeENB_ID) {
        BIT_STRING_t *bit_string = &eNB_ID->choice.homeENB_ID;
        assert(bit_string);

        bit_string->size = 4;
        bit_string->buf = CALLOC(bit_string->size, sizeof(uint8_t));

        bit_string->buf[0] = enb_id >> 20;
        bit_string->buf[1] = enb_id >> 12;
        bit_string->buf[2] = enb_id >> 4;
        bit_string->buf[3] = (enb_id & 0xf) << 4;

        bit_string->bits_unused = 4;
    } else {
        abort();
    }

}

void uint32_to_BIT_STRING_CELL_ID(uint32_t enb_id, S1AP_CellIdentity_t* cell_id)
{
    assert(cell_id);
    
    BIT_STRING_t *bit_string = cell_id;
    assert(bit_string);

    bit_string->size = 4;
    bit_string->buf = CALLOC(bit_string->size, sizeof(uint8_t));
    bit_string->buf[0] = enb_id >> 24;
    bit_string->buf[1] = enb_id >> 16;
    bit_string->buf[2] = enb_id >> 8;
    bit_string->buf[3] = enb_id;
    bit_string->bits_unused = 4;

}

pkbuf_t* s1ap_build_s1_setup_request(s1_setup_req_arg* args)
{
    int i, j;
    S1AP_S1AP_PDU_t pdu;
    S1AP_InitiatingMessage_t* initiatingMessage = NULL;

    S1AP_S1SetupRequest_t* S1SetupRequest = NULL;
    S1AP_S1SetupRequestIEs_t* ie = NULL;

    S1AP_Global_ENB_ID_t* Global_ENB_ID_t = NULL;
    S1AP_ENBname_t* ENBname_t = NULL;
    S1AP_SupportedTAs_t* SupportedTAs_t = NULL;
    S1AP_SupportedTAs_Item_t* SupportedTAs_Item_t = NULL;
    S1AP_BPLMNs_t* BPLMNs_t = NULL;
    S1AP_PLMNidentity_t* plmn = NULL;
    S1AP_PagingDRX_t* PagingDRX_t = NULL;             
    // ogs_debug("Error Indication");

    memset(&pdu, 0, sizeof(S1AP_S1AP_PDU_t));
    pdu.present = S1AP_S1AP_PDU_PR_initiatingMessage;
    pdu.choice.initiatingMessage = 
        (struct S1AP_InitiatingMessage*)CALLOC(1, sizeof(S1AP_InitiatingMessage_t));

    initiatingMessage = pdu.choice.initiatingMessage;
    initiatingMessage->procedureCode = S1AP_ProcedureCode_id_S1Setup;
    initiatingMessage->criticality = S1AP_Criticality_reject;
    initiatingMessage->value.present =
        S1AP_InitiatingMessage__value_PR_S1SetupRequest;

    S1SetupRequest = &initiatingMessage->value.choice.S1SetupRequest;

    // if (args->enb_name)
    // {
        ie = (struct S1AP_S1SetupRequestIEs*)CALLOC(1, sizeof(S1AP_S1SetupRequestIEs_t));
        if(!ie)
        {
            perror("memory is not enough");
            return NULL;
        }

        ASN_SEQUENCE_ADD(&S1SetupRequest->protocolIEs, ie);

        ie->id = S1AP_ProtocolIE_ID_id_eNBname;
        ie->criticality = S1AP_Criticality_ignore;
        ie->value.present = S1AP_S1SetupRequestIEs__value_PR_ENBname;

        ENBname_t = &ie->value.choice.ENBname;
        
    // }
    // assignment enb_name.
    if (ENBname_t) 
    {
        asn_buffer_to_OCTET_STRING(args->enb_name,
                strlen(args->enb_name), ENBname_t);
    }
    // if (args->global_enb_id.enb_id) 
    // {
        ie = (struct S1AP_S1SetupRequestIEs*)CALLOC(1, sizeof(S1AP_S1SetupRequestIEs_t));
        if(!ie)
        {
            perror("memory is not enough");
            return NULL;
        }

        ASN_SEQUENCE_ADD(&S1SetupRequest->protocolIEs, ie);

        ie->id = S1AP_ProtocolIE_ID_id_Global_ENB_ID;
        ie->criticality = S1AP_Criticality_reject;
        ie->value.present = S1AP_S1SetupRequestIEs__value_PR_Global_ENB_ID;

        Global_ENB_ID_t = &ie->value.choice.Global_ENB_ID;
        asn_buffer_to_OCTET_STRING(&args->global_enb_id.plmn_id, sizeof(plmn_id_t), &Global_ENB_ID_t->pLMNidentity);
        
        S1AP_ENB_ID_t* enb_id_t = &Global_ENB_ID_t->eNB_ID;
        enb_id_t->present = S1AP_ENB_ID_PR_macroENB_ID;
        s1ap_uint32_to_ENB_ID(S1AP_ENB_ID_PR_macroENB_ID, args->global_enb_id.enb_id, enb_id_t);
        // ogs_debug("    MME_UE_S1AP_ID[%d]", (int)*mme_ue_s1ap_id);
    // }

    
    ie = (struct S1AP_S1SetupRequestIEs*)CALLOC(1, sizeof(S1AP_S1SetupRequestIEs_t));
    if(!ie)
    {
        perror("memory is not enough");
        return NULL;
    }
    ASN_SEQUENCE_ADD(&S1SetupRequest->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_SupportedTAs;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present = S1AP_S1SetupRequestIEs__value_PR_SupportedTAs;
    SupportedTAs_t = &ie->value.choice.SupportedTAs;
    for(i = 0; i < args->num_supported_tas; i++)
    {   
        SupportedTAs_Item_t =(S1AP_SupportedTAs_Item_t*)CALLOC(1, sizeof(struct S1AP_SupportedTAs_Item));
        if(!SupportedTAs_Item_t)
        {
            perror("memory is not enough");
            return NULL;
        }
        asn_uint16_to_OCTET_STRING(args->supported_tas[i].tac, &SupportedTAs_Item_t->tAC);
        for(j = 0; j < args->supported_tas[i].nums_plmn_id; j++)
        {
            BPLMNs_t = &SupportedTAs_Item_t->broadcastPLMNs;
            plmn = (S1AP_PLMNidentity_t*)CALLOC(1, sizeof(S1AP_PLMNidentity_t));
            asn_buffer_to_OCTET_STRING(&((args->supported_tas[i]).plmn_id[j]), sizeof(plmn_id_t), plmn);
            
            ASN_SEQUENCE_ADD(&BPLMNs_t->list, plmn);
        }
        ASN_SEQUENCE_ADD(&SupportedTAs_t->list, SupportedTAs_Item_t);
    }

    ie = (struct S1AP_S1SetupRequestIEs*)CALLOC(1, sizeof(S1AP_S1SetupRequestIEs_t));
    if(!ie)
    {
        perror("memory is not enough");
        return NULL;
    }
    ASN_SEQUENCE_ADD(&S1SetupRequest->protocolIEs, ie);
    ie->id = S1AP_ProtocolIE_ID_id_pagingDRX;
    ie->criticality = S1AP_Criticality_ignore;
    ie->value.present = S1AP_S1SetupRequestIEs__value_PR_PagingDRX;
    PagingDRX_t = &ie->value.choice.PagingDRX;

    *PagingDRX_t = S1AP_PagingDRX_v128;

    return s1ap_encode(&pdu);
}


pkbuf_t* s1ap_build_s1_setup_response(s1_setup_res_arg* args)
{
    int i, j;

    S1AP_S1AP_PDU_t pdu;
    S1AP_SuccessfulOutcome_t *successfulOutcome = NULL;
    S1AP_S1SetupResponse_t *S1SetupResponse = NULL;

    S1AP_S1SetupResponseIEs_t *ie = NULL;
    S1AP_ServedGUMMEIs_t *ServedGUMMEIs = NULL;
    S1AP_RelativeMMECapacity_t *RelativeMMECapacity = NULL;
    S1AP_MMEname_t *MMEname = NULL;
    S1AP_ServedGUMMEIsItem_t *ServedGUMMEIsItem = NULL;
    S1AP_PLMNidentity_t *PLMNidentity = NULL;
    S1AP_MME_Group_ID_t *MME_Group_ID = NULL;
    S1AP_MME_Code_t* MME_Code = NULL;

    memset(&pdu, 0, sizeof (S1AP_S1AP_PDU_t));
    pdu.present = S1AP_S1AP_PDU_PR_successfulOutcome;
    pdu.choice.successfulOutcome = CALLOC(1, sizeof(S1AP_SuccessfulOutcome_t));

    successfulOutcome = pdu.choice.successfulOutcome;
    successfulOutcome->procedureCode = S1AP_ProcedureCode_id_S1Setup;
    successfulOutcome->criticality = S1AP_Criticality_reject;
    successfulOutcome->value.present =
        S1AP_SuccessfulOutcome__value_PR_S1SetupResponse;

    S1SetupResponse = &successfulOutcome->value.choice.S1SetupResponse;

    // if (args->mme_name) {
        ie = CALLOC(1, sizeof(S1AP_S1SetupResponseIEs_t));
        ASN_SEQUENCE_ADD(&S1SetupResponse->protocolIEs, ie);

        ie->id = S1AP_ProtocolIE_ID_id_MMEname;
        ie->criticality = S1AP_Criticality_ignore;
        ie->value.present = S1AP_S1SetupResponseIEs__value_PR_MMEname;

        MMEname = &ie->value.choice.MMEname;
    // }

    ie = CALLOC(1, sizeof(S1AP_S1SetupResponseIEs_t));
    ASN_SEQUENCE_ADD(&S1SetupResponse->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_ServedGUMMEIs;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present = S1AP_S1SetupResponseIEs__value_PR_ServedGUMMEIs;

    ServedGUMMEIs = &ie->value.choice.ServedGUMMEIs;

    ie = CALLOC(1, sizeof(S1AP_S1SetupResponseIEs_t));
    ASN_SEQUENCE_ADD(&S1SetupResponse->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_RelativeMMECapacity;
    ie->criticality = S1AP_Criticality_ignore;
    ie->value.present = S1AP_S1SetupResponseIEs__value_PR_RelativeMMECapacity;

    RelativeMMECapacity = &ie->value.choice.RelativeMMECapacity;

    if (MMEname) {
        asn_buffer_to_OCTET_STRING(args->mme_name,
                strlen(args->mme_name), MMEname);
    }

    for (i = 0; i < args->num_of_served_gummei; i++) 
    {
        ServedGUMMEIsItem = (S1AP_ServedGUMMEIsItem_t *)
            CALLOC(1, sizeof(S1AP_ServedGUMMEIsItem_t));

        //served_gummei_t *served_gummei = args->served_gummei[i];
        
        for (j = 0; j < (args->served_gummei[i]).num_of_plmn_id; j++) 
        {
            PLMNidentity = (S1AP_PLMNidentity_t *)
                CALLOC(1, sizeof(S1AP_PLMNidentity_t));
            asn_buffer_to_OCTET_STRING(&((args->served_gummei[i]).plmn_id[j]), sizeof(plmn_id_t), PLMNidentity);
            ASN_SEQUENCE_ADD(&ServedGUMMEIsItem->servedPLMNs.list, PLMNidentity);
        }

        for (j = 0; j < (args->served_gummei[i]).num_of_group_id; j++) {

            MME_Group_ID = (S1AP_MME_Group_ID_t *)
                CALLOC(1, sizeof(S1AP_MME_Group_ID_t));
            asn_uint16_to_OCTET_STRING((args->served_gummei[i]).mme_gid[j], MME_Group_ID);
            ASN_SEQUENCE_ADD(&ServedGUMMEIsItem->servedGroupIDs.list, MME_Group_ID);
        }

        for (j = 0; j < (args->served_gummei[i]).num_of_mme_code; j++) {

            MME_Code = (S1AP_MME_Code_t *)
                CALLOC(1, sizeof(S1AP_MME_Code_t));
            asn_uint8_to_OCTET_STRING((args->served_gummei[i]).mme_code[j], MME_Code);
            ASN_SEQUENCE_ADD(&ServedGUMMEIsItem->servedMMECs.list, MME_Code);

        }
        ASN_SEQUENCE_ADD(&ServedGUMMEIs->list, ServedGUMMEIsItem);
    }

    *RelativeMMECapacity = args->relativeMMECapacity;
    return s1ap_encode(&pdu);
}


pkbuf_t* s1ap_build_initial_uemessage(initial_uemessage_arg* args, pkbuf_t* buf)
{
    // int i, j;
    S1AP_S1AP_PDU_t pdu;
    S1AP_InitiatingMessage_t* initiatingMessage = NULL;

    S1AP_InitialUEMessage_t* InitialUEMessage_t = NULL;
    S1AP_InitialUEMessage_IEs_t* ie = NULL;

    S1AP_ENB_UE_S1AP_ID_t* ENB_UE_S1AP_ID_t = NULL;
    S1AP_NAS_PDU_t* NAS_PDU_t = NULL;
    S1AP_TAI_t* TAI_t = NULL;
    S1AP_EUTRAN_CGI_t* EUTRAN_CGI_t = NULL;
    S1AP_RRC_Establishment_Cause_t* RRC_Establishment_Cause_t = NULL;

    memset(&pdu, 0, sizeof(S1AP_S1AP_PDU_t));
    pdu.present = S1AP_S1AP_PDU_PR_initiatingMessage;
    pdu.choice.initiatingMessage = 
        (struct S1AP_InitiatingMessage*)CALLOC(1, sizeof(S1AP_InitiatingMessage_t));
    
    initiatingMessage = pdu.choice.initiatingMessage;
    initiatingMessage->procedureCode = S1AP_ProcedureCode_id_initialUEMessage;
    initiatingMessage->criticality = S1AP_Criticality_ignore;
    initiatingMessage->value.present =
        S1AP_InitiatingMessage__value_PR_InitialUEMessage;
    InitialUEMessage_t = &initiatingMessage->value.choice.InitialUEMessage;
    // 1.
    ie = (S1AP_InitialUEMessage_IEs_t*)CALLOC(1, sizeof(S1AP_InitialUEMessage_IEs_t));
    ASN_SEQUENCE_ADD(&InitialUEMessage_t->protocolIEs, ie);
    
    ie->id = S1AP_ProtocolIE_ID_id_eNB_UE_S1AP_ID;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present = S1AP_InitialUEMessage_IEs__value_PR_ENB_UE_S1AP_ID;
    ENB_UE_S1AP_ID_t = &ie->value.choice.ENB_UE_S1AP_ID;
    *ENB_UE_S1AP_ID_t = args->end_ue_s1ap_id;
    // 2.
    if(buf)
    {
        ie = (S1AP_InitialUEMessage_IEs_t*)CALLOC(1, sizeof(S1AP_InitialUEMessage_IEs_t));
        ASN_SEQUENCE_ADD(&InitialUEMessage_t->protocolIEs, ie);
        ie->id = S1AP_ProtocolIE_ID_id_NAS_PDU;
        ie->criticality = S1AP_Criticality_reject;
        ie->value.present = S1AP_InitialUEMessage_IEs__value_PR_NAS_PDU;
        NAS_PDU_t = &ie->value.choice.NAS_PDU;
        NAS_PDU_t->size = buf->len;
        NAS_PDU_t->buf = CALLOC(NAS_PDU_t->size, sizeof(uint8_t));
        memcpy(NAS_PDU_t->buf, buf->data, NAS_PDU_t->size);
        pkbuf_free(buf);
    }
    // 3.
    ie = (S1AP_InitialUEMessage_IEs_t*)CALLOC(1, sizeof(S1AP_InitialUEMessage_IEs_t));
    ASN_SEQUENCE_ADD(&InitialUEMessage_t->protocolIEs, ie);
    ie->id = S1AP_ProtocolIE_ID_id_TAI;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present = S1AP_InitialUEMessage_IEs__value_PR_TAI;
    TAI_t = &ie->value.choice.TAI;
    asn_buffer_to_OCTET_STRING(&args->tai.plmn_id, sizeof(plmn_id_t), &TAI_t->pLMNidentity);
    asn_uint16_to_OCTET_STRING(args->tai.tac, &TAI_t->tAC);
    // 4.
    ie = (S1AP_InitialUEMessage_IEs_t*)CALLOC(1, sizeof(S1AP_InitialUEMessage_IEs_t));
    ASN_SEQUENCE_ADD(&InitialUEMessage_t->protocolIEs, ie);
    ie->id = S1AP_ProtocolIE_ID_id_EUTRAN_CGI;
    ie->criticality = S1AP_Criticality_ignore;
    ie->value.present = S1AP_InitialUEMessage_IEs__value_PR_EUTRAN_CGI;
    EUTRAN_CGI_t = &ie->value.choice.EUTRAN_CGI;
    asn_buffer_to_OCTET_STRING(&args->eutran_cgi.plmn_id, sizeof(plmn_id_t), &EUTRAN_CGI_t->pLMNidentity);
    uint32_to_BIT_STRING_CELL_ID(args->eutran_cgi.cell_id, &EUTRAN_CGI_t->cell_ID);
    // asn_buffer_to_BIT_STRING(&args->eutran_cgi.cell_id, sizeof(uint32_t), 0, &EUTRAN_CGI_t->cell_ID);
    // 5.
    ie = (S1AP_InitialUEMessage_IEs_t*)CALLOC(1, sizeof(S1AP_InitialUEMessage_IEs_t));
    ASN_SEQUENCE_ADD(&InitialUEMessage_t->protocolIEs, ie);
    ie->id = S1AP_ProtocolIE_ID_id_RRC_Establishment_Cause;
    ie->criticality = S1AP_Criticality_ignore;
    ie->value.present = S1AP_InitialUEMessage_IEs__value_PR_RRC_Establishment_Cause;
    RRC_Establishment_Cause_t = &ie->value.choice.RRC_Establishment_Cause;
    *RRC_Establishment_Cause_t = args->id_rrc_establismnet_cause;

    return s1ap_encode(&pdu);
}   


pkbuf_t* s1ap_build_initialContextSetupReq()
{
    S1AP_S1AP_PDU_t pdu;
    S1AP_InitiatingMessage_t* initiatingMessage = NULL;
    S1AP_InitialContextSetupRequest_t* InitialContextSetupRequest_t = NULL;
    S1AP_InitialContextSetupRequestIEs_t* ie = NULL;

    S1AP_MME_UE_S1AP_ID_t* MME_UE_S1AP_ID_t = NULL;
    S1AP_ENB_UE_S1AP_ID_t* ENB_UE_S1AP_ID_t = NULL;
    S1AP_UEAggregateMaximumBitrate_t* UEAggregateMaximumBitrate_t = NULL;
    S1AP_E_RABToBeSetupListCtxtSUReq_t* E_RABToBeSetupListCtxtSUReq_t = NULL;
    S1AP_UESecurityCapabilities_t* UESecurityCapabilities_t = NULL;
    S1AP_SecurityKey_t* SecurityKey_t = NULL;

    memset(&pdu, 0, sizeof(S1AP_S1AP_PDU_t));
    pdu.present = S1AP_S1AP_PDU_PR_initiatingMessage;
    pdu.choice.initiatingMessage = CALLOC(1, sizeof(S1AP_InitiatingMessage_t));
    initiatingMessage = pdu.choice.initiatingMessage;
    initiatingMessage->procedureCode = S1AP_ProcedureCode_id_InitialContextSetup;
    initiatingMessage->criticality = S1AP_Criticality_reject;
    initiatingMessage->value.present = S1AP_InitiatingMessage__value_PR_InitialContextSetupRequest;
    InitialContextSetupRequest_t = &initiatingMessage->value.choice.InitialContextSetupRequest;

    // 1.
    ie = CALLOC(1, sizeof(S1AP_InitialContextSetupRequestIEs_t));
    ASN_SEQUENCE_ADD(&InitialContextSetupRequest_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_MME_UE_S1AP_ID;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present =
        S1AP_InitialContextSetupRequestIEs__value_PR_MME_UE_S1AP_ID;
    MME_UE_S1AP_ID_t = &ie->value.choice.MME_UE_S1AP_ID;
    *MME_UE_S1AP_ID_t = 2;

    // 2.
    ie = CALLOC(1, sizeof(S1AP_InitialContextSetupRequestIEs_t));
    ASN_SEQUENCE_ADD(&InitialContextSetupRequest_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_eNB_UE_S1AP_ID;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present =
        S1AP_InitialContextSetupRequestIEs__value_PR_ENB_UE_S1AP_ID;
    ENB_UE_S1AP_ID_t = &ie->value.choice.ENB_UE_S1AP_ID;
    *ENB_UE_S1AP_ID_t = 1;

    // 3.
    ie = CALLOC(1, sizeof(S1AP_InitialContextSetupRequestIEs_t));
    ASN_SEQUENCE_ADD(&InitialContextSetupRequest_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_uEaggregateMaximumBitrate;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present =
        S1AP_InitialContextSetupRequestIEs__value_PR_UEAggregateMaximumBitrate;
    UEAggregateMaximumBitrate_t = &ie->value.choice.UEAggregateMaximumBitrate;
    asn_uint642INTEGER(
            &UEAggregateMaximumBitrate_t->uEaggregateMaximumBitRateUL,
            0x1312D00);
    asn_uint642INTEGER(
            &UEAggregateMaximumBitrate_t->uEaggregateMaximumBitRateDL,
            0x989680);
    // 4.
    ie = CALLOC(1, sizeof(S1AP_InitialContextSetupRequestIEs_t));
    ASN_SEQUENCE_ADD(&InitialContextSetupRequest_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_E_RABToBeSetupListCtxtSUReq;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present =
        S1AP_InitialContextSetupRequestIEs__value_PR_E_RABToBeSetupListCtxtSUReq;
    E_RABToBeSetupListCtxtSUReq_t = &ie->value.choice.E_RABToBeSetupListCtxtSUReq;
    /*  */
    S1AP_E_RABToBeSetupItemCtxtSUReqIEs_t* item = NULL;
    S1AP_E_RABToBeSetupItemCtxtSUReq_t* e_rab = NULL;

    item = CALLOC(1, sizeof(S1AP_E_RABToBeSetupItemCtxtSUReqIEs_t));
    ASN_SEQUENCE_ADD(&E_RABToBeSetupListCtxtSUReq_t->list, item);
    item->id = S1AP_ProtocolIE_ID_id_E_RABToBeSetupItemCtxtSUReq;
    item->criticality = S1AP_Criticality_reject;
    item->value.present = S1AP_E_RABToBeSetupItemCtxtSUReqIEs__value_PR_E_RABToBeSetupItemCtxtSUReq;
    e_rab = &item->value.choice.E_RABToBeSetupItemCtxtSUReq;

    e_rab->e_RAB_ID = 5;
    e_rab->e_RABlevelQoSParameters.qCI = 6;
    e_rab->e_RABlevelQoSParameters.allocationRetentionPriority.
        priorityLevel = S1AP_PriorityLevel_highest;
    e_rab->e_RABlevelQoSParameters.allocationRetentionPriority.
        pre_emptionCapability =
            S1AP_Pre_emptionCapability_shall_not_trigger_pre_emption;
    e_rab->e_RABlevelQoSParameters.allocationRetentionPriority.
        pre_emptionVulnerability =
            S1AP_Pre_emptionVulnerability_pre_emptable;

    ogs_ip_t sgw_s1u_ip;
    memset(&sgw_s1u_ip, 0 , sizeof(ogs_ip_t));
    sgw_s1u_ip.addr = 0x4e02b0c0;
    //memcpy(sgw_s1u_ip.addr6, 0, 16);
    sgw_s1u_ip.ipv4 = 1;

    int rv = asn_ip_to_BIT_STRING(&sgw_s1u_ip, &e_rab->transportLayerAddress);
    if(rv < 0) return NULL;
    
    asn_uint32_to_OCTET_STRING(0x00f401fb, &e_rab->gTP_TEID);

    /*  */
    // 5.
    ie = CALLOC(1, sizeof(S1AP_InitialContextSetupRequestIEs_t));
    ASN_SEQUENCE_ADD(&InitialContextSetupRequest_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_UESecurityCapabilities;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present =
        S1AP_InitialContextSetupRequestIEs__value_PR_UESecurityCapabilities;
    UESecurityCapabilities_t = &ie->value.choice.UESecurityCapabilities;
    UESecurityCapabilities_t->encryptionAlgorithms.size = 2;
    UESecurityCapabilities_t->encryptionAlgorithms.buf =
        CALLOC(UESecurityCapabilities_t->encryptionAlgorithms.size,
                    sizeof(uint8_t));
    UESecurityCapabilities_t->encryptionAlgorithms.bits_unused = 0;
    UESecurityCapabilities_t->encryptionAlgorithms.buf[0] = (0xf0 << 1);

    UESecurityCapabilities_t->integrityProtectionAlgorithms.size = 2;
    UESecurityCapabilities_t->integrityProtectionAlgorithms.buf =
        CALLOC(UESecurityCapabilities_t->
                        integrityProtectionAlgorithms.size, sizeof(uint8_t));
    UESecurityCapabilities_t->integrityProtectionAlgorithms.bits_unused = 0;
    UESecurityCapabilities_t->integrityProtectionAlgorithms.buf[0] = (0xf0 << 1);

    // 6.
    ie = CALLOC(1, sizeof(S1AP_InitialContextSetupRequestIEs_t));
    ASN_SEQUENCE_ADD(&InitialContextSetupRequest_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_SecurityKey;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present =
        S1AP_InitialContextSetupRequestIEs__value_PR_SecurityKey;
    SecurityKey_t = &ie->value.choice.SecurityKey;

    SecurityKey_t->size = 32;
    SecurityKey_t->buf = CALLOC(SecurityKey_t->size, sizeof(uint8_t));
    SecurityKey_t->bits_unused = 0;

    memcpy(SecurityKey_t->buf, buf, SecurityKey_t->size);

    return s1ap_encode(&pdu);
}


pkbuf_t* s1ap_build_initialContextSetupRes()
{
    S1AP_S1AP_PDU_t pdu;
    S1AP_SuccessfulOutcome_t* SuccessfulOutcome_t = NULL;
    S1AP_InitialContextSetupResponse_t* InitialContextSetupResponse_t = NULL;
    S1AP_InitialContextSetupResponseIEs_t* ie = NULL;

    S1AP_MME_UE_S1AP_ID_t* MME_UE_S1AP_ID_t = NULL;
    S1AP_ENB_UE_S1AP_ID_t* ENB_UE_S1AP_ID_t = NULL;
    S1AP_E_RABSetupListCtxtSURes_t* E_RABSetupListCtxtSURes_t = NULL;

    memset(&pdu, 0, sizeof(S1AP_S1AP_PDU_t));
    pdu.present = S1AP_S1AP_PDU_PR_successfulOutcome;
    pdu.choice.successfulOutcome = CALLOC(1, sizeof(S1AP_SuccessfulOutcome_t));
    SuccessfulOutcome_t = pdu.choice.successfulOutcome;
    SuccessfulOutcome_t->procedureCode = S1AP_ProcedureCode_id_InitialContextSetup;
    SuccessfulOutcome_t->criticality = S1AP_Criticality_reject;
    SuccessfulOutcome_t->value.present = S1AP_SuccessfulOutcome__value_PR_InitialContextSetupResponse;
    InitialContextSetupResponse_t = &SuccessfulOutcome_t->value.choice.InitialContextSetupResponse;

    // 1.
    ie = CALLOC(1, sizeof(S1AP_InitialContextSetupResponseIEs_t));
    ASN_SEQUENCE_ADD(&InitialContextSetupResponse_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_MME_UE_S1AP_ID;
    ie->criticality = S1AP_Criticality_ignore;
    ie->value.present =
        S1AP_InitialContextSetupResponseIEs__value_PR_MME_UE_S1AP_ID;
    MME_UE_S1AP_ID_t = &ie->value.choice.MME_UE_S1AP_ID;
    *MME_UE_S1AP_ID_t = 2;

    // 2.
    ie = CALLOC(1, sizeof(S1AP_InitialContextSetupResponseIEs_t));
    ASN_SEQUENCE_ADD(&InitialContextSetupResponse_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_eNB_UE_S1AP_ID;
    ie->criticality = S1AP_Criticality_ignore;
    ie->value.present =
        S1AP_InitialContextSetupResponseIEs__value_PR_ENB_UE_S1AP_ID;
    ENB_UE_S1AP_ID_t = &ie->value.choice.ENB_UE_S1AP_ID;
    *ENB_UE_S1AP_ID_t = 1;

    // 3.
    ie = CALLOC(1, sizeof(S1AP_InitialContextSetupResponseIEs_t));
    ASN_SEQUENCE_ADD(&InitialContextSetupResponse_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_E_RABSetupListCtxtSURes;
    ie->criticality = S1AP_Criticality_ignore;
    ie->value.present =
        S1AP_InitialContextSetupResponseIEs__value_PR_E_RABSetupListCtxtSURes;
    E_RABSetupListCtxtSURes_t = &ie->value.choice.E_RABSetupListCtxtSURes;

    S1AP_E_RABSetupItemCtxtSUResIEs_t* E_RABSetupItemCtxtSUResIEs_t = NULL;
    S1AP_E_RABSetupItemCtxtSURes_t* E_RABSetupItemCtxtSURes_t = NULL;

    E_RABSetupItemCtxtSUResIEs_t = CALLOC(1, sizeof(S1AP_E_RABSetupItemCtxtSUResIEs_t));
    ASN_SEQUENCE_ADD(&E_RABSetupListCtxtSURes_t->list, E_RABSetupItemCtxtSUResIEs_t);
    
    E_RABSetupItemCtxtSUResIEs_t->id = S1AP_ProtocolIE_ID_id_E_RABSetupItemCtxtSURes;
    E_RABSetupItemCtxtSUResIEs_t->criticality = S1AP_Criticality_ignore;
    E_RABSetupItemCtxtSUResIEs_t->value.present = S1AP_E_RABSetupItemCtxtSUResIEs__value_PR_E_RABSetupItemCtxtSURes;
    E_RABSetupItemCtxtSURes_t = &E_RABSetupItemCtxtSUResIEs_t->value.choice.E_RABSetupItemCtxtSURes;

    E_RABSetupItemCtxtSURes_t->e_RAB_ID = 5;

    ogs_ip_t sgw_s1u_ip;
    memset(&sgw_s1u_ip, 0 , sizeof(ogs_ip_t));
    sgw_s1u_ip.addr = 0x5a32a8c0;
    //memcpy(sgw_s1u_ip.addr6, 0, 16);
    sgw_s1u_ip.ipv4 = 1;

    int rv = asn_ip_to_BIT_STRING(&sgw_s1u_ip, &E_RABSetupItemCtxtSURes_t->transportLayerAddress);
    if(rv < 0) return NULL;

    asn_uint32_to_OCTET_STRING(0x5de00634, &E_RABSetupItemCtxtSURes_t->gTP_TEID);

    return s1ap_encode(&pdu);
}


pkbuf_t* s1ap_build_uecontext_release_request()
{
    S1AP_S1AP_PDU_t pdu;
    S1AP_InitiatingMessage_t* initiatingMessage = NULL;
    S1AP_UEContextReleaseRequest_t* UEContextReleaseRequest_t = NULL;
    S1AP_UEContextReleaseRequest_IEs_t* ie = NULL;

    S1AP_MME_UE_S1AP_ID_t* MME_UE_S1AP_ID_t = NULL;
    S1AP_ENB_UE_S1AP_ID_t* ENB_UE_S1AP_ID_t = NULL;
    S1AP_Cause_t* Cause_t = NULL;

    memset(&pdu, 0, sizeof(S1AP_S1AP_PDU_t));
    pdu.present = S1AP_S1AP_PDU_PR_initiatingMessage;
    pdu.choice.initiatingMessage = CALLOC(1, sizeof(S1AP_InitiatingMessage_t));
    initiatingMessage = pdu.choice.initiatingMessage;
    initiatingMessage->procedureCode = S1AP_ProcedureCode_id_UEContextReleaseRequest;
    initiatingMessage->criticality = S1AP_Criticality_ignore;
    initiatingMessage->value.present = S1AP_InitiatingMessage__value_PR_UEContextReleaseRequest;
    UEContextReleaseRequest_t = &initiatingMessage->value.choice.UEContextReleaseRequest;

    // 1.
    ie = CALLOC(1, sizeof(S1AP_UEContextReleaseRequest_IEs_t));
    ASN_SEQUENCE_ADD(&UEContextReleaseRequest_t->protocolIEs, ie);
    ie->id = S1AP_ProtocolIE_ID_id_MME_UE_S1AP_ID;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present = S1AP_UEContextReleaseRequest_IEs__value_PR_MME_UE_S1AP_ID;
    MME_UE_S1AP_ID_t = &ie->value.choice.MME_UE_S1AP_ID;
    *MME_UE_S1AP_ID_t = 2;

    // 2.
    ie = CALLOC(1, sizeof(S1AP_UEContextReleaseRequest_IEs_t));
    ASN_SEQUENCE_ADD(&UEContextReleaseRequest_t->protocolIEs, ie);
    ie->id = S1AP_ProtocolIE_ID_id_eNB_UE_S1AP_ID;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present = S1AP_UEContextReleaseRequest_IEs__value_PR_ENB_UE_S1AP_ID;
    MME_UE_S1AP_ID_t = &ie->value.choice.ENB_UE_S1AP_ID;
    *MME_UE_S1AP_ID_t = 1;

    // 3.
    ie = CALLOC(1, sizeof(S1AP_UEContextReleaseRequest_IEs_t));
    ASN_SEQUENCE_ADD(&UEContextReleaseRequest_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_Cause;
    ie->criticality = S1AP_Criticality_ignore;
    ie->value.present = S1AP_UEContextReleaseRequest_IEs__value_PR_Cause;
    Cause_t = &ie->value.choice.Cause;

    S1AP_CauseRadioNetwork_t* CauseRadioNetwork_t = NULL;
    Cause_t->present = S1AP_Cause_PR_radioNetwork;
    CauseRadioNetwork_t = &Cause_t->choice.radioNetwork;
    *CauseRadioNetwork_t = S1AP_CauseRadioNetwork_user_inactivity;

    return s1ap_encode(&pdu);
}

pkbuf_t* s1ap_build_uplink_nas_transport(pkbuf_t* detach_buf)
{
    S1AP_S1AP_PDU_t pdu;
    S1AP_InitiatingMessage_t* initiatingMessage = NULL;
    S1AP_UplinkNASTransport_t* UplinkNASTransport_t = NULL;
    S1AP_UplinkNASTransport_IEs_t* ie = NULL;

    S1AP_MME_UE_S1AP_ID_t* MME_UE_S1AP_ID_t = NULL;
    S1AP_ENB_UE_S1AP_ID_t* ENB_UE_S1AP_ID_t = NULL;
    S1AP_NAS_PDU_t* NAS_PDU_t = NULL;
    S1AP_EUTRAN_CGI_t* EUTRAN_CGI_t = NULL;
    S1AP_TAI_t* TAI_t = NULL;

    memset(&pdu, 0, sizeof(S1AP_S1AP_PDU_t));
    pdu.present = S1AP_S1AP_PDU_PR_initiatingMessage;
    pdu.choice.initiatingMessage = CALLOC(1, sizeof(S1AP_InitiatingMessage_t));
    initiatingMessage = pdu.choice.initiatingMessage;
    initiatingMessage->procedureCode = S1AP_ProcedureCode_id_uplinkNASTransport;
    initiatingMessage->criticality = S1AP_Criticality_ignore;
    initiatingMessage->value.present = S1AP_InitiatingMessage__value_PR_UplinkNASTransport;
    UplinkNASTransport_t = &initiatingMessage->value.choice.UplinkNASTransport;

    // 1.
    ie = CALLOC(1, sizeof(S1AP_UplinkNASTransport_IEs_t));
    ASN_SEQUENCE_ADD(&UplinkNASTransport_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_MME_UE_S1AP_ID;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present = S1AP_UplinkNASTransport_IEs__value_PR_MME_UE_S1AP_ID;
    MME_UE_S1AP_ID_t = &ie->value.choice.MME_UE_S1AP_ID;
    *MME_UE_S1AP_ID_t = 2;   
    // 2.
    ie = CALLOC(1, sizeof(S1AP_UplinkNASTransport_IEs_t));
    ASN_SEQUENCE_ADD(&UplinkNASTransport_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_eNB_UE_S1AP_ID;
    ie->criticality = S1AP_Criticality_reject;
    ie->value.present = S1AP_UplinkNASTransport_IEs__value_PR_ENB_UE_S1AP_ID;
    ENB_UE_S1AP_ID_t = &ie->value.choice.ENB_UE_S1AP_ID;
    *ENB_UE_S1AP_ID_t = 1;   
    // 3.

    if(detach_buf)
    {
        ie = CALLOC(1, sizeof(S1AP_UplinkNASTransport_IEs_t));
        ASN_SEQUENCE_ADD(&UplinkNASTransport_t->protocolIEs, ie);

        ie->id = S1AP_ProtocolIE_ID_id_NAS_PDU;
        ie->criticality = S1AP_Criticality_reject;
        ie->value.present = S1AP_UplinkNASTransport_IEs__value_PR_NAS_PDU;
        NAS_PDU_t = &ie->value.choice.NAS_PDU;
        NAS_PDU_t->size = detach_buf->len;
        NAS_PDU_t->buf = CALLOC(NAS_PDU_t->size, sizeof(uint8_t));
        memcpy(NAS_PDU_t->buf, detach_buf->data, NAS_PDU_t->size);
    }
    
    //4.
/////////////
    plmn_id_t plmn;
    plmn.mcc1 = 4;
    plmn.mcc2 = 6;
    plmn.mcc3 = 0;
    plmn.mnc1 = 15;
    plmn.mnc2 = 0;
    plmn.mnc3 = 5;
////////////////
    ie = CALLOC(1, sizeof(S1AP_UplinkNASTransport_IEs_t));
    ASN_SEQUENCE_ADD(&UplinkNASTransport_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_EUTRAN_CGI;
    ie->criticality = S1AP_Criticality_ignore;
    ie->value.present = S1AP_UplinkNASTransport_IEs__value_PR_EUTRAN_CGI;
    EUTRAN_CGI_t = &ie->value.choice.EUTRAN_CGI;

    asn_buffer_to_OCTET_STRING(&plmn, sizeof(plmn_id_t), &EUTRAN_CGI_t->pLMNidentity);
    uint32_to_BIT_STRING_CELL_ID(0x18aeecd0, &EUTRAN_CGI_t->cell_ID);
    // 5.
    ie = CALLOC(1, sizeof(S1AP_UplinkNASTransport_IEs_t));
    ASN_SEQUENCE_ADD(&UplinkNASTransport_t->protocolIEs, ie);

    ie->id = S1AP_ProtocolIE_ID_id_TAI;
    ie->criticality = S1AP_Criticality_ignore;
    ie->value.present = S1AP_UplinkNASTransport_IEs__value_PR_TAI;
    TAI_t = &ie->value.choice.TAI;
    asn_buffer_to_OCTET_STRING(&plmn, sizeof(plmn_id_t), &TAI_t->pLMNidentity);
    asn_uint16_to_OCTET_STRING(0x0001, &TAI_t->tAC);

    return s1ap_encode(&pdu);

}