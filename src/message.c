#include "message.h"
#include <assert.h>
#include "s1ap_msg_hdr.h"

int s1ap_decode(s1ap_message_t *message, pkbuf_t *pkbuf)
{
    int rv;
    assert(message);
    assert(pkbuf);
    assert(pkbuf->data);
    assert(pkbuf->len);

    rv = asn_decode_custom(&asn_DEF_S1AP_S1AP_PDU,
            message, sizeof(s1ap_message_t), pkbuf);
    if (rv != 0) {
        // ogs_warn("Failed to decode S1AP-PDU");
        return rv;
    }

    // if (ogs_log_get_domain_level(OGS_LOG_DOMAIN) >= OGS_LOG_TRACE)
    //     asn_fprint(stdout, &asn_DEF_S1AP_S1AP_PDU, message);

    return 0;    
}
pkbuf_t* s1ap_encode(s1ap_message_t *message)
{
    pkbuf_t *pkbuf = NULL;

    assert(message);

    // if (log_get_domain_level(OGS_LOG_DOMAIN) >= OGS_LOG_TRACE)
    //     asn_fprint(stdout, &asn_DEF_S1AP_S1AP_PDU, message);

    pkbuf = asn_encode_custom(&asn_DEF_S1AP_S1AP_PDU, message);
    if (!pkbuf) {
        //ogs_error("ogs_asn_encode() failed");
        return NULL;
    }

    return pkbuf;
}
void s1ap_free(s1ap_message_t *message)
{
    assert(message);
    asn_free_custom(&asn_DEF_S1AP_S1AP_PDU, message);
}