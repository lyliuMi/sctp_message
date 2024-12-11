#ifndef S1AP_MESSAGE_H
#define S1AP_MESSAGE_H

#include "pkbuf.h"
#include "s1ap_msg_hdr.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct S1AP_S1AP_PDU s1ap_message_t;

int s1ap_decode(s1ap_message_t *message, pkbuf_t *pkbuf);
pkbuf_t* s1ap_encode(s1ap_message_t *message);
void s1ap_free(s1ap_message_t *message);

#ifdef __cplusplus
}
#endif

#endif