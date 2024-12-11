#include "s1ap_path.h"
#include "context.h"
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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