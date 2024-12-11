#ifndef _S1AP_PATH_H
#define _S1AP_PATH_H

#include "s1ap_msg_hdr.h"
#include "message.h"


void s1ap_ENB_ID_to_uint32(S1AP_ENB_ID_t *eNB_ID, uint32_t *uint32);

void s1ap_handle_s1_setup_request(s1ap_message_t *message);

#endif