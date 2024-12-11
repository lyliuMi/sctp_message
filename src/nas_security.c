#include "nas_security.h"

pkbuf_t *nas_eps_security_encode(ogs_nas_eps_message_t *message)
{
    int integrity_protected = 0;
    int new_security_context = 0;
    int ciphered = 0;
    ogs_nas_eps_security_header_t h;
    pkbuf_t *new = NULL;

    //
    uint8_t knas_int[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 
    0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10};
    uint32_t count = 12345; // 下行计数器
    // assert(mme_ue);
    
    assert(message);

    switch (message->h.security_header_type) {
    case OGS_NAS_SECURITY_HEADER_PLAIN_NAS_MESSAGE:
        return ogs_nas_eps_plain_encode(message);
    case OGS_NAS_SECURITY_HEADER_INTEGRITY_PROTECTED:
        integrity_protected = 1;
        break;
    case OGS_NAS_SECURITY_HEADER_INTEGRITY_PROTECTED_AND_CIPHERED:
        integrity_protected = 1;
        ciphered = 1;
        break;
    case OGS_NAS_SECURITY_HEADER_INTEGRITY_PROTECTED_AND_NEW_SECURITY_CONTEXT:
        integrity_protected = 1;
        new_security_context = 1;
        break;
    case OGS_NAS_SECURITY_HEADER_INTEGRITY_PROTECTED_AND_CIPHTERD_WITH_NEW_INTEGRITY_CONTEXT:
        integrity_protected = 1;
        new_security_context = 1;
        ciphered = 1;
        break;
    default:
        break;
        return NULL;
    }

    memset(&h, 0, sizeof(h));
    h.security_header_type = message->h.security_header_type;
    h.protocol_discriminator = message->h.protocol_discriminator;
    h.sequence_number = (count & 0xff);

    new = ogs_nas_eps_plain_encode(message);
    if (!new) {
        // ogs_error("ogs_nas_eps_plain_encode() failed");
        return NULL;
    }

    if (ciphered) {
        /* encrypt NAS message */
        ogs_nas_encrypt(1, NULL, 1, NAS_SECURITY_BEARER,
            OGS_NAS_SECURITY_DOWNLINK_DIRECTION, new);
    }

    /* encode sequence number */
    assert(pkbuf_push(new, 1));
    *(uint8_t *)(new->data) = h.sequence_number;


    if (integrity_protected) {
        uint8_t mac[NAS_SECURITY_MAC_SIZE];

        /* calculate NAS MAC(message authentication code) */
        ogs_nas_mac_calculate(1,
            knas_int, count, NAS_SECURITY_BEARER, 
            OGS_NAS_SECURITY_DOWNLINK_DIRECTION, new, mac);
        memcpy(&h.message_authentication_code, mac, sizeof(mac));
    }

    count = (count + 1) & 0xffffff; /* Use 24bit */

    /* encode all security header */
    assert(pkbuf_push(new, 5));
    memcpy(new->data, &h, sizeof(ogs_nas_eps_security_header_t));

    // mme_ue->security_context_available = 1;

    return new;
}
int nas_eps_security_decode(ogs_nas_security_header_type_t security_header_type, pkbuf_t *pkbuf)
{

}