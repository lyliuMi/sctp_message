#ifndef _SCTP_H_
#define _SCTP_H_

#include "socket.h"
#include <netinet/in.h>
#include <netinet/sctp.h>

#include <sys/socket.h>
#include <sys/types.h>

#include "core.h"

#define ogs_sctp_ppid_in_pkbuf(__pkBUF)         (__pkBUF)->param[0]
#define ogs_sctp_stream_no_in_pkbuf(__pkBUF)    (__pkBUF)->param[1]

typedef struct sctp_sock_s
{
    int type;
    sock_t* sock;
    sockaddr_t* addr;
}sctp_sock_t;

typedef struct sockopt_s
{
    struct {
        uint32_t spp_hbinterval;
        uint32_t spp_sackdelay;
        uint32_t srto_initial;
        uint32_t srto_min;
        uint32_t srto_max;
        uint16_t sinit_num_ostreams;
        uint16_t sinit_max_instreams;
        uint16_t sinit_max_attempts;
        uint16_t sinit_max_init_timeo;
    } sctp;
    int sctp_nodelay;
    int tcp_nodelay;
    struct 
    {
        int l_onoff;
        int l_linger;
    } so_linger;
    const char *so_bindtodevice;
}sockopt_t;

typedef struct sctp_info_s 
{
    uint32_t ppid;
    uint16_t stream_no;
    uint16_t inbound_streams;
    uint16_t outbound_streams;
}sctp_info_t;

// void sctp_init(uint16_t port);
// void sctp_final(void);

sock_t* Sctp_socket(int family, int type);

sock_t* Sctp_server(int type, sockaddr_t* sa_list, sockopt_t* socket_option);
sock_t* Sctp_client(int type, sockaddr_t* sa_list, sockopt_t* socket_option);

int Sctp_bind(sock_t* sock, sockaddr_t* sa_list);
int Sctp_connect(sock_t* sock, sockaddr_t* sa_list);
int Sctp_listen(sock_t *sock);

int Sctp_peer_addr_params(sock_t* sock, sockopt_t* option);
int Sctp_rto_info(sock_t* sock, sockopt_t* option);
int Sctp_initmsg(sock_t* sock, sockopt_t* option);
int Sctp_nodelay(sock_t* sock, int on);
int Sctp_so_linger(sock_t* sock, int l_linger);

int Sctp_sendmsg(sock_t* sock, const void* msg, size_t len, sockaddr_t* to, uint32_t ppid, uint16_t stream_no);
int Sctp_recvmsg(sock_t* sock, void* msg, size_t len, sockaddr_t* from, sctp_info_t* sinfo, int* msg_flags);
int Sctp_recvdata(sock_t* sock, void* msg, size_t len,sockaddr_t* from, sctp_info_t* sinfo);

int Sctp_senddata(sock_t* sock, pkbuf_t* pkbuf, sockaddr_t* addr);
void Sctp_write_to_buffer(sctp_sock_t* sctp, pkbuf_t* pkbuf);
void Sctp_flush_and_destroy(sctp_sock_t* sctp);



#endif