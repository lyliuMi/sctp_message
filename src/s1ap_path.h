#ifndef _S1AP_PATH_H
#define _S1AP_PATH_H

#include "s1ap_msg_hdr.h"
#include "message.h"
#include "socket.h"
#include "sctp.h"

void s1ap_ENB_ID_to_uint32(S1AP_ENB_ID_t *eNB_ID, uint32_t *uint32);

void s1ap_handle_s1_setup_request(s1ap_message_t *message);

int send_s1ap_s1_setup_req(sock_t* sctp, sockaddr_t* addr);

int send_s1ap_initialueMsg(sock_t* sctp, sockaddr_t* addr);

int send_s1ap_s1_setup_res(sock_t* sctp, sockaddr_t* addr);

int send_s1ap_initialContextSetupReq(sock_t* sctp, sockaddr_t* addr);

int send_s1ap_initialContextSetupRes(sock_t* sctp, sockaddr_t* addr);

int send_s1ap_uecontext_release_request(sock_t* sctp, sockaddr_t* addr);

int send_s1ap_uplink_nas_transport(sock_t* sctp, sockaddr_t* addr);
#endif