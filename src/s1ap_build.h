#ifndef _S1AP_BUILD_H
#define _S1AP_BUILD_H

#include "pkbuf.h"
#include "context.h"
#include "s1ap_msg_hdr.h"

#ifdef __cplusplus
extern "C" {
#endif

void s1ap_uint32_to_ENB_ID(S1AP_ENB_ID_PR present, uint32_t enb_id, S1AP_ENB_ID_t *eNB_ID);

void uint32_to_BIT_STRING_CELL_ID(uint32_t enb_id, S1AP_CellIdentity_t* cell_id);

pkbuf_t* s1ap_build_s1_setup_request(s1_setup_req_arg* args);

pkbuf_t* s1ap_build_s1_setup_response(s1_setup_res_arg* args);


pkbuf_t* s1ap_build_initial_uemessage(initial_uemessage_arg* args, pkbuf_t* buf);


#ifdef __cplusplus
}
#endif

#endif