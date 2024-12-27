#include "s1ap_path.h"
#include "context.h"
#include "s1ap_build.h"
#include "nas_build.h"

unsigned char invalid_s1ap_message[10][20] = {
{
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
    0x0D, 0x0E, 0x0F, 0x10,
    0xFF, 0xFF, 0xFF, 0xFF
},
{
    0x01, 0x03, 0x43, 0xa4, 0xc1, 0x31, 0x17, 0x10, 0x39, 0x4A, 0x0B, 0x0C,
    0x02, 0x09, 0x06, 0x14,
    0xFF, 0xFF, 0xFF, 0xFF
},
{
    0x17, 0x16, 0x13, 0x94, 0x15, 0x36, 0x47, 0x58, 0x39, 0x1A, 0x2B, 0x1C,
    0x0D, 0x0E, 0x0F, 0x10,
    0xFF, 0xFF, 0xFF, 0xFF
},
{
    0x01, 0x11, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
    0x0D, 0x0E, 0x0F, 0x10,
    0xFF, 0xFF, 0xFF, 0xFF
},
{
    0x01, 0x13, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
    0x0D, 0x0E, 0x0F, 0x10,
    0xFF, 0xFF, 0xFF, 0xFF
},
{
    0x01, 0x35, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
    0x0D, 0x0E, 0x0F, 0x10,
    0xFF, 0xFF, 0xFF, 0xFF
},
{
    0x01, 0x32, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
    0x0D, 0x0E, 0x0F, 0x10,
    0xFF, 0xFF, 0xFF, 0xFF
},
{
    0x01, 0x29, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
    0x0D, 0x0E, 0x0F, 0x10,
    0xFF, 0xFF, 0xFF, 0xFF
},
{
    0x01, 0x25, 0xd3, 0x12, 0x41, 0x53, 0x12, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
    0x0D, 0x0E, 0x0F, 0x10,
    0xFF, 0xFF, 0xFF, 0xFF
},
{
    0x01, 0x24, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
    0x0D, 0x0E, 0x0F, 0x10,
    0xFF, 0xFF, 0xFF, 0xFF
}
};
void s1ap_ENB_ID_to_uint32(S1AP_ENB_ID_t *eNB_ID, uint32_t *uint32)
{
    assert(uint32);
    assert(eNB_ID);

    if (eNB_ID->present == S1AP_ENB_ID_PR_homeENB_ID) {
        uint8_t *buf = eNB_ID->choice.homeENB_ID.buf;
        assert(buf);
        *uint32 = (buf[0] << 20) + (buf[1] << 12) + (buf[2] << 4) +
            ((buf[3] & 0xf0) >> 4);

    } else if (eNB_ID->present == S1AP_ENB_ID_PR_macroENB_ID) {
        uint8_t *buf = eNB_ID->choice.macroENB_ID.buf;
        assert(buf);
        *uint32 = (buf[0] << 12) + (buf[1] << 4) + ((buf[2] & 0xf0) >> 4);
    } else {
        abort();
    }
}

void s1ap_handle_bytype(s1ap_message_t *message)
{
    int i, j;
    if(message->present == S1AP_S1AP_PDU_PR_NOTHING)
    {
        printf("s1ap message S1AP_S1AP_PDU_PR_NOTHING\n");
    }
    else if(message->present == S1AP_S1AP_PDU_PR_initiatingMessage)
    {
        printf("s1ap message S1AP_S1AP_PDU_PR_initiatingMessage\n");
        S1AP_InitiatingMessage_t *initiatingMessage = message->choice.initiatingMessage;
        printf("initiatingMessage->procedureCode = %ld\n", (S1AP_ProcedureCode_t)initiatingMessage->procedureCode);
        switch(initiatingMessage->procedureCode)
        {   
            case S1AP_ProcedureCode_id_S1Setup:
                s1ap_handle_s1_setup_request(message);
                break;

            default:
                break;
        }

    }
    else if(message->present == S1AP_S1AP_PDU_PR_successfulOutcome)
    {
        printf("s1ap message S1AP_S1AP_PDU_PR_successfulOutcome\n");
        S1AP_SuccessfulOutcome_t *successfulOutcome = message->choice.successfulOutcome;

        printf("initiatingMessage->procedureCode = %ld\n", successfulOutcome->procedureCode);
    }
    else if(message->present == S1AP_S1AP_PDU_PR_unsuccessfulOutcome)
    {
        printf("s1ap message S1AP_S1AP_PDU_PR_unsuccessfulOutcome\n");

    }


}

void s1ap_handle_s1_setup_request(s1ap_message_t *message)
{
    int i, j;

    S1AP_InitiatingMessage_t *initiatingMessage = NULL;
    S1AP_S1SetupRequest_t *S1SetupRequest = NULL;

    S1AP_S1SetupRequestIEs_t *ie = NULL;
    S1AP_Global_ENB_ID_t *Global_ENB_ID = NULL;
    S1AP_SupportedTAs_t *SupportedTAs = NULL;
    S1AP_PagingDRX_t *PagingDRX = NULL;

    uint32_t enb_id;
    plmn_id_t plmn_id;
    uint16_t tac;
    S1AP_Cause_PR group = S1AP_Cause_PR_NOTHING;
    long cause = 0;

    assert(message);
    initiatingMessage = message->choice.initiatingMessage;
    assert(initiatingMessage);
    S1SetupRequest = &initiatingMessage->value.choice.S1SetupRequest;
    assert(S1SetupRequest);

    for (i = 0; i < S1SetupRequest->protocolIEs.list.count; i++) {
        ie = S1SetupRequest->protocolIEs.list.array[i];
        switch (ie->id) {
        case S1AP_ProtocolIE_ID_id_Global_ENB_ID:
            Global_ENB_ID = &ie->value.choice.Global_ENB_ID;
            break;
        case S1AP_ProtocolIE_ID_id_SupportedTAs:
            SupportedTAs = &ie->value.choice.SupportedTAs;
            break;
        case S1AP_ProtocolIE_ID_id_DefaultPagingDRX:
            PagingDRX = &ie->value.choice.PagingDRX;
            break;
        default:
            break;
        }
    }

    if (!Global_ENB_ID) {
        group = S1AP_Cause_PR_misc;
        cause = S1AP_CauseProtocol_semantic_error;


        return;
    }

    if (!SupportedTAs) {

        group = S1AP_Cause_PR_misc;
        cause = S1AP_CauseProtocol_semantic_error;

        return;
    }

    s1ap_ENB_ID_to_uint32(&Global_ENB_ID->eNB_ID, &enb_id);
    memcpy(&plmn_id, Global_ENB_ID->pLMNidentity.buf, sizeof(plmn_id_t));
    printf("    PLMN_ID[MCC:%d MNC:%d] \n",
            plmn_id.mcc1*100 + plmn_id.mcc2*10 + plmn_id.mcc3, 
            plmn_id.mnc1*100 + plmn_id.mnc2*10 + plmn_id.mnc3);

    if (PagingDRX)
        printf("    PagingDRX[%ld]\n", *PagingDRX);

    /* Parse Supported TA */
    for (i = 0; i < SupportedTAs->list.count; i++) {
        S1AP_SupportedTAs_Item_t *SupportedTAs_Item = NULL;
        S1AP_TAC_t *tAC = NULL;

        SupportedTAs_Item =
            (S1AP_SupportedTAs_Item_t *)SupportedTAs->list.array[i];
        assert(SupportedTAs_Item);
        tAC = &SupportedTAs_Item->tAC;
        assert(tAC);

        for (j = 0; j < SupportedTAs_Item->broadcastPLMNs.list.count; j++) {
            S1AP_PLMNidentity_t *pLMNidentity = NULL;
            pLMNidentity = (S1AP_PLMNidentity_t *)
                SupportedTAs_Item->broadcastPLMNs.list.array[j];
            assert(pLMNidentity);

            memcpy(&tac, tAC->buf, sizeof(uint16_t));
            memcpy(&plmn_id, pLMNidentity->buf, sizeof(plmn_id_t));
            printf("    PLMN_ID[MCC:%d MNC:%d] TAC[%d] \n",
            plmn_id.mcc1*100 + plmn_id.mcc2*10 + plmn_id.mcc3, 
            plmn_id.mnc1*100 + plmn_id.mnc2*10 + plmn_id.mnc3,
            ntohs(tac));
        }
    }


}


int send_s1ap_s1_setup_req(sock_t* sctp, sockaddr_t* addr)
{
    ssize_t size;
    pkbuf_t* pkbuf = NULL;
    s1_setup_req_arg args;
    init_s1_setup_req_args(&args);

    pkbuf = s1ap_build_s1_setup_request(&args);
    if(!pkbuf)
        return -1;
    size = Sctp_senddata(sctp, pkbuf, addr);
    if(size < 0)
    {
        perror("send s1_setup_req error:");
        return -1;
    }
    printf("send success: size = %ld\n", size);

    return 0;
}

int send_s1ap_initialueMsg(sock_t* sctp, sockaddr_t* addr)
{
    ssize_t size;
    initial_uemessage_arg ue_args;
    init_initial_uemessage_arg(&ue_args);

    pkbuf_t* pkbuf = nas_build_attach_request();
    if(!pkbuf)
        return -1;
    pkbuf_t* pkbuf2 = s1ap_build_initial_uemessage(&ue_args, pkbuf);
    if(!pkbuf2)
        return -1;
    
    size = Sctp_senddata(sctp, pkbuf2, addr);
    if(size < 0)
    {
        perror("send s1ap_initialueMsg error:");
        return -1;
    }
    printf("send success: size = %ld\n", size);

    return 0;
}

int send_s1ap_s1_setup_res(sock_t* sctp, sockaddr_t* addr)
{
    ssize_t size;
    s1_setup_res_arg res_args;
    init_s1_setup_res_args(&res_args);

    pkbuf_t* pkbuf = s1ap_build_s1_setup_response(&res_args);
    if(!pkbuf)
        return -1;
    
    size = Sctp_senddata(sctp, pkbuf, addr);
    if(size < 0)
    {
        perror("send s1_setup_res error:");
        return -1;
    }
    printf("send success: size = %ld\n", size);

    return 0;
}


int send_s1ap_initialContextSetupReq(sock_t* sctp, sockaddr_t* addr)
{
    ssize_t size;
    // s1_setup_res_arg res_args;
    // init_s1_setup_res_args(&res_args);

    pkbuf_t* pkbuf = s1ap_build_initialContextSetupReq();
    if(!pkbuf)
        return -1;
    
    size = Sctp_senddata(sctp, pkbuf, addr);
    if(size < 0)
    {
        perror("send s1ap_initialContextSetupReq error:");
        return -1;
    }
    printf("send success: size = %ld\n", size);

    return 0;
}

int send_s1ap_initialContextSetupRes(sock_t* sctp, sockaddr_t* addr)
{
    ssize_t size;
    // s1_setup_res_arg res_args;
    // init_s1_setup_res_args(&res_args);

    pkbuf_t* pkbuf = s1ap_build_initialContextSetupRes();
    if(!pkbuf)
        return -1;
    
    size = Sctp_senddata(sctp, pkbuf, addr);
    if(size < 0)
    {
        perror("send s1ap_build_initialContextSetupRes error:");
        return -1;
    }
    printf("send success: size = %ld\n", size);

    return 0;
}

int send_s1ap_uecontext_release_request(sock_t* sctp, sockaddr_t* addr)
{
    ssize_t size;
    // s1_setup_res_arg res_args;
    // init_s1_setup_res_args(&res_args);

    pkbuf_t* pkbuf = s1ap_build_uecontext_release_request();
    if(!pkbuf)
        return -1;
    
    size = Sctp_senddata(sctp, pkbuf, addr);
    if(size < 0)
    {
        perror("send s1ap_build_uecontext_release_request error:");
        return -1;
    }
    printf("send success: size = %ld\n", size);

    return 0;   
}


int send_s1ap_uplink_nas_transport(sock_t* sctp, sockaddr_t* addr)
{
    ssize_t size;
    // s1_setup_res_arg res_args;
    // init_s1_setup_res_args(&res_args);

    pkbuf_t* pkbuf = nas_build_detach_request();
    pkbuf_t* pkbuf2 = s1ap_build_uplink_nas_transport(pkbuf);
    if(!pkbuf)
        return -1;
    if(!pkbuf2)
        return -1;
    size = Sctp_senddata(sctp, pkbuf2, addr);
    if(size < 0)
    {
        perror("send send_s1ap_uplink_nas_transport error:");
        return -1;
    }
    printf("send success: size = %ld\n", size);

    return 0;   
}

int send_s1ap_decode_fail_pkts(sock_t* sctp, sockaddr_t* addr)
{
    int i;
    ssize_t size;
    // s1_setup_res_arg res_args;
    // init_s1_setup_res_args(&res_args);

    for(i = 0;i < 10; i++)
    {
        pkbuf_t* pkbuf = pkbuf_alloc(NULL, OGS_MAX_SDU_LEN);
        if(!pkbuf)
            return -1;
        memcpy(pkbuf->data, invalid_s1ap_message[i], 20);
        pkbuf->len = 20;

        size = Sctp_senddata(sctp, pkbuf, addr);
        if(size < 0)
        {
            perror("send send_s1ap_uplink_nas_transport error:");
            return -1;
        }
        printf("send success: size = %ld\n", size);

    }

    return 0;   
}