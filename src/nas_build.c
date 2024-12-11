#include "nas_build.h"
#include "nas_security.h"

extern int ogs_nas_eps_encode_attach_request(pkbuf_t *pkbuf, ogs_nas_eps_message_t *message);

pkbuf_t* nas_build_attach_request()
{
    ogs_nas_eps_message_t message;
    pkbuf_t *pkbuf = NULL;
    ogs_nas_eps_attach_request_t *attach_request = &message.emm.attach_request;

    memset(&message, 0, sizeof(message));
    message.h.security_header_type =
       OGS_NAS_SECURITY_HEADER_INTEGRITY_PROTECTED;
    message.h.protocol_discriminator = OGS_NAS_PROTOCOL_DISCRIMINATOR_EMM;

    message.emm.h.protocol_discriminator = OGS_NAS_PROTOCOL_DISCRIMINATOR_EMM;
    message.emm.h.message_type = OGS_NAS_EPS_ATTACH_REQUEST;

    ogs_nas_eps_attach_type_t* eps_attach_type = &attach_request->eps_attach_type;
    ogs_nas_eps_mobile_identity_t* eps_mobile_identity = &attach_request->eps_mobile_identity;
    ogs_nas_ue_network_capability_t* ue_network_capability = &attach_request->ue_network_capability;
    ogs_nas_esm_message_container_t* esm_message_container = &attach_request->esm_message_container;

    eps_attach_type->tsc = 0;
    eps_attach_type->nas_key_set_identifier = 7;
    eps_attach_type->spare = 0;
    eps_attach_type->value = 1;

    // 2.
    eps_mobile_identity->length = 11;
    eps_mobile_identity->guti.spare = 0;
    eps_mobile_identity->guti.odd_even = 0;
    eps_mobile_identity->guti.type = 6;
    eps_mobile_identity->guti.nas_plmn_id.mcc1 = 4;
    eps_mobile_identity->guti.nas_plmn_id.mcc2 = 6;
    eps_mobile_identity->guti.nas_plmn_id.mcc3 = 0;
    eps_mobile_identity->guti.nas_plmn_id.mnc1 = 0;
    eps_mobile_identity->guti.nas_plmn_id.mnc2 = 0;
    eps_mobile_identity->guti.nas_plmn_id.mnc3 = 5;
    eps_mobile_identity->guti.mme_gid = 0x0243;
    eps_mobile_identity->guti.mme_code = 1;
    eps_mobile_identity->guti.m_tmsi = 0x1d74bac0;
    // 3.
    ue_network_capability->length = 4;
    ue_network_capability->eea0 = 1;
    ue_network_capability->eea1 = 0;
    ue_network_capability->eea2 = 0;
    ue_network_capability->eea3 = 0;
    ue_network_capability->eea4 = 0;
    ue_network_capability->eea5 = 0;
    ue_network_capability->eea6 = 0;
    ue_network_capability->eea7 = 0;

    ue_network_capability->eia0 = 1;
    ue_network_capability->eia1 = 0;
    ue_network_capability->eia2 = 0;
    ue_network_capability->eia3 = 0;
    ue_network_capability->eia4 = 0;
    ue_network_capability->eia5 = 0;
    ue_network_capability->eia6 = 0;
    ue_network_capability->eia7 = 0;

    ue_network_capability->uea0 = 1;
    ue_network_capability->uea1 = 0;
    ue_network_capability->uea2 = 0;
    ue_network_capability->uea3 = 0;
    ue_network_capability->uea4 = 0;
    ue_network_capability->uea5 = 0;
    ue_network_capability->uea6 = 0;
    ue_network_capability->uea7 = 0;

    ue_network_capability->ucs2 = 1;
    ue_network_capability->uia1 = 0;
    ue_network_capability->uia2 = 0;
    ue_network_capability->uia3 = 0;
    ue_network_capability->uia4 = 0;
    ue_network_capability->uia5 = 0;
    ue_network_capability->uia6 = 0;
    ue_network_capability->uia7 = 0;

    // 4.
    esm_message_container->length = 100;
    char* buffer = (char*)malloc(100);
    strcpy(buffer, "pdn");
    // char buffer[100] = "pdn";
    esm_message_container->buffer = buffer;

    //
    if((pkbuf = nas_eps_security_encode(&message)) < 0)
    {
        perror("nas msg enconde fail:");
        return NULL;
    }

    return pkbuf;
}

pkbuf_t *nas_build_identity_request()
{
    ogs_nas_eps_message_t message;
    ogs_nas_eps_identity_request_t *identity_request =
        &message.emm.identity_request;

    memset(&message, 0, sizeof(message));
    message.emm.h.protocol_discriminator = OGS_NAS_PROTOCOL_DISCRIMINATOR_EMM;
    message.emm.h.message_type = OGS_NAS_EPS_IDENTITY_REQUEST;

    identity_request->identity_type.type = OGS_NAS_IDENTITY_TYPE_2_IMSI;

    return ogs_nas_eps_plain_encode(&message);
}

pkbuf_t *nas_build_service_reject(ogs_nas_emm_cause_t emm_cause)
{
    ogs_nas_eps_message_t message;
    ogs_nas_eps_service_reject_t *service_reject = &message.emm.service_reject;

    memset(&message, 0, sizeof(message));
    message.emm.h.protocol_discriminator = OGS_NAS_PROTOCOL_DISCRIMINATOR_EMM;
    message.emm.h.message_type = OGS_NAS_EPS_SERVICE_REJECT;

    service_reject->emm_cause = emm_cause;

    return ogs_nas_eps_plain_encode(&message);
}
