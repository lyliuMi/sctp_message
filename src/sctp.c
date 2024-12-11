#include "sctp.h"
// #include <linux/sctp.h>
// #include <netinet/sctp.h>
static void sockopt_init(sockopt_t *option);
static int sctp_setsockopt_event_subscribe_workaround(
        int fd, const struct sctp_event_subscribe *event_subscribe);
static int subscribe_to_events(sock_t *sock);
static int determine_sctp_sockopt_event_subscribe_size(void);
static int byte_nonzero(const uint8_t *u8, unsigned int offset, unsigned int u8_size);
static int sctp_setsockopt_paddrparams_workaround(
        int fd, const struct sctp_paddrparams *paddrparams);
sock_t* Sctp_socket(int family, int type)
{
    sock_t* sock = Sock_socket(family, type, IPPROTO_SCTP);
    if(!sock)
        return NULL;

    int rv = subscribe_to_events(sock);
    if(rv != 0)
    {
        Sock_destroy(sock);
        return NULL;
    }
    return sock;
}

sock_t* Sctp_server(int type, sockaddr_t* sa_list, sockopt_t* socket_option)
{
    int rv;
    sock_t* new = NULL;
    sockaddr_t* addr;
    sockopt_t option;

    if(!sa_list)
    {
        return NULL;
    }
    sockopt_init(&option);
    if (socket_option)
        memcpy(&option, socket_option, sizeof option);

    addr = sa_list;
    while (addr)
    {
        new = Sctp_socket(addr->sa.sa_family, type);
        if (new)
        {
            rv = Sctp_peer_addr_params(new, &option);
            if((rv != 0))
                return NULL;

            rv = Sctp_rto_info(new, &option);
            if((rv != 0))
                return NULL;

            rv = Sctp_initmsg(new, &option);
            if((rv != 0))
                return NULL;

            if(option.sctp_nodelay == 1) 
            {
                rv = Sctp_nodelay(new, 1);
                if((rv != 0))
                    return NULL;
            }
            if(option.so_linger.l_onoff == 1) 
            {
                rv = Sctp_so_linger(new, option.so_linger.l_linger);
                if((rv != 0))
                    return NULL;
            }
            // rv = listen_reusable(new->fd, 1);
            int on = 1;
            rv = setsockopt(new->fd, SOL_SOCKET, SO_REUSEADDR, (void *)&on, sizeof(int));
            if((rv != 0))
                return NULL;
            if (Sock_bind(new, addr) == 0) {
                break;
            }
            Sock_destroy(new);
        }
        addr = addr->next;
    }

    if (addr == NULL) {
        return NULL;
    }
    if(!new)
        return NULL;
    rv = Sock_listen(new);
    if(rv != 0)
        return NULL;
    return new;
}
sock_t* Sctp_client(int type, sockaddr_t* sa_list, sockopt_t* socket_option)
{
    int rv;
    sock_t *new = NULL;
    sockaddr_t *addr;
    sockopt_t option;

    if(!sa_list)
        return NULL;
    sockopt_init(&option);
    if (socket_option)
        memcpy(&option, socket_option, sizeof option);
    addr = sa_list;
    while (addr) {
        new = Sctp_socket(addr->sa.sa_family, type);
        if (new) 
        {
            rv = Sctp_peer_addr_params(new, &option);
            if((rv != 0))
                return NULL;

            rv = Sctp_rto_info(new, &option);
            if((rv != 0))
                return NULL;

            rv = Sctp_initmsg(new, &option);
            if((rv != 0))
                return NULL;

            if (option.sctp_nodelay == 1) {
                rv = Sctp_nodelay(new, 1);
                if((rv != 0))
                return NULL;
            }

            if (option.so_linger.l_onoff == 1) {
                rv = Sctp_so_linger(new, option.so_linger.l_linger);
                if((rv != 0))
                    return NULL;
            }
            sockaddr_t addr_t;
            addr_t.sin.sin_port = htons(36412);
            addr_t.sin.sin_family = AF_INET;
            inet_pton(AF_INET, "192.168.177.129", &addr_t.sin.sin_addr);

            Sock_bind(new, &addr_t);
            if (Sock_connect(new, addr) == 0) 
                break;
            Sock_destroy(new);
        }
        addr = addr->next;
    }
    if (addr == NULL) {
        return NULL;
    }
    if(!new)
        return NULL;

    return new;
}

int Sctp_bind(sock_t* sock, sockaddr_t* sa_list)
{
    return 0;
}
int Sctp_connect(sock_t* sock, sockaddr_t* sa_list)
{
    sockaddr_t *addr;
    if(!sock)
        return -1;
    if(!sa_list)
        return -1;
        
    addr = sa_list;
    while (addr) 
    {
        if (Sock_connect(sock, addr) == 0) 
            break;
        addr = addr->next;
    }

    if (addr == NULL) 
        return -1;

    return 0;
}
int Sctp_listen(sock_t *sock)
{
    return 0;
}

int Sctp_peer_addr_params(sock_t* sock, sockopt_t* option)
{
    struct sctp_paddrparams paddrparams;
    socklen_t socklen;

    if(!sock)
        return -1;
    if(!option)
        return -1;

    memset(&paddrparams, 0, sizeof(paddrparams));
    socklen = sizeof(paddrparams);
    if (getsockopt(sock->fd, IPPROTO_SCTP, SCTP_PEER_ADDR_PARAMS, &paddrparams, &socklen) != 0) 
        return -1;
    
    paddrparams.spp_hbinterval = option->sctp.spp_hbinterval;
    paddrparams.spp_sackdelay = option->sctp.spp_sackdelay;
    if (sctp_setsockopt_paddrparams_workaround(sock->fd, &paddrparams) < 0) 
        return -1;

    return 0;
}
int Sctp_rto_info(sock_t* sock, sockopt_t* option)
{
    struct sctp_rtoinfo rtoinfo;
    socklen_t socklen;

    if(!sock)
        return -1;
    if(!option)
        return -1;

    memset(&rtoinfo, 0, sizeof(rtoinfo));
    socklen = sizeof(rtoinfo);

    if (getsockopt(sock->fd, IPPROTO_SCTP, SCTP_RTOINFO,
                            &rtoinfo, &socklen) != 0) 
        return -1;

    rtoinfo.srto_initial = option->sctp.srto_initial;
    rtoinfo.srto_min = option->sctp.srto_min;
    rtoinfo.srto_max = option->sctp.srto_max;

    if (setsockopt(sock->fd, IPPROTO_SCTP, SCTP_RTOINFO,
                            &rtoinfo, sizeof(rtoinfo)) != 0) 
        return -1;
    return 0;
}
int Sctp_initmsg(sock_t* sock, sockopt_t* option)
{
    struct sctp_initmsg initmsg;
    socklen_t socklen;

    if(!sock)
        return -1;
    if(!option)
        return -1;
    if(option->sctp.sinit_num_ostreams < 1)
        return -1;
    memset(&initmsg, 0, sizeof(initmsg));
    socklen = sizeof(initmsg);
    if (getsockopt(sock->fd, IPPROTO_SCTP, SCTP_INITMSG,
                            &initmsg, &socklen) != 0) 
        return -1;
    

    initmsg.sinit_num_ostreams = option->sctp.sinit_num_ostreams;
    initmsg.sinit_max_instreams = option->sctp.sinit_max_instreams;
    initmsg.sinit_max_attempts = option->sctp.sinit_max_attempts;
    initmsg.sinit_max_init_timeo = option->sctp.sinit_max_init_timeo;

    if (setsockopt(sock->fd, IPPROTO_SCTP, SCTP_INITMSG,
                            &initmsg, sizeof(initmsg)) != 0) 
        return -1;

    return 0;
}
int Sctp_nodelay(sock_t* sock, int on)
{
    if(!sock)
        return -1;
    if (setsockopt(sock->fd, IPPROTO_SCTP, SCTP_NODELAY,
                &on, sizeof(on)) != 0) 
        return -1;

    return 0;
}
int Sctp_so_linger(sock_t* sock, int l_linger)
{
    if(!sock)
        return -1;
    //return ogs_so_linger(sock->fd, l_linger);
    struct linger l;
    int rc;
    if(sock->fd == -1)
        return -1;

    memset(&l, 0, sizeof(l));
    l.l_onoff = 1;
    l.l_linger = l_linger;

    rc = setsockopt(sock->fd, SOL_SOCKET, SO_LINGER, (void *)&l, sizeof(struct linger));
    if (rc != 0) 
        return -1;
    return 0;
}

int Sctp_sendmsg(sock_t* sock, const void* msg, size_t len, sockaddr_t* to, uint32_t ppid, uint16_t stream_no)
{
    socklen_t addrlen = 0;
    if(!sock)
        return -1;
    if(to)
    {
        switch(to->sa.sa_family)
        {
            case AF_INET:
                addrlen = sizeof(struct sockaddr_in);
                break;
            case AF_INET6:
                addrlen = sizeof(struct sockaddr_in6);
                break;
            default:
                return -1;
        }
    }
    return sctp_sendmsg(sock->fd, msg, len,
            to ? &to->sa : NULL, addrlen,
            htobe32(ppid),
            0,  /* flags */
            stream_no,
            0,  /* timetolive */
            0); /* context */
}
int Sctp_recvmsg(sock_t* sock, void* msg, size_t len, sockaddr_t* from, sctp_info_t* sinfo, int* msg_flags)
{
    int size;
    socklen_t addrlen = sizeof(struct sockaddr_storage);
    sockaddr_t addr;

    int flags = 0;
    struct sctp_sndrcvinfo sndrcvinfo;

    if(!sock)
        return -1;

    memset(&sndrcvinfo, 0, sizeof sndrcvinfo);
    memset(&addr, 0, sizeof addr);
    size = sctp_recvmsg(sock->fd, msg, len, &addr.sa, &addrlen,
                &sndrcvinfo, &flags);
    if (size < 0) 
        return size;

    if(from){
        memcpy(from, &addr, sizeof(sockaddr_t));
    }
    if (msg_flags) {
        *msg_flags = flags;
    }
    if (sinfo) {
        sinfo->ppid = be32toh(sndrcvinfo.sinfo_ppid);
        sinfo->stream_no = sndrcvinfo.sinfo_stream;
    }
    return size;    
}
int Sctp_recvdata(sock_t* sock, void* msg, size_t len, sockaddr_t* from, sctp_info_t* sinfo)
{
    int size;
    int flags = 0;
    do {
        size = Sctp_recvmsg(sock, msg, len, from, sinfo, &flags);
        if (size < 0 || size >= 32768) 
            return size;
        if (flags & MSG_NOTIFICATION) {
            /* Nothing */
        } else if (flags & MSG_EOR) {
            break;
        } else 
        {
            return -1;
        }
    } while(1);

    return size;
}

int Sctp_senddata(sock_t* sock, pkbuf_t* pkbuf, sockaddr_t* addr)
{
    int sent;

    if(!sock)
        return -1;
    if(!pkbuf)
        return -1;
    sent = Sctp_sendmsg(sock, pkbuf->data, pkbuf->len, addr,
            ogs_sctp_ppid_in_pkbuf(pkbuf), ogs_sctp_stream_no_in_pkbuf(pkbuf));
    if (sent < 0 || sent != pkbuf->len) {
        pkbuf_free(pkbuf);
        return -1;
    }

    pkbuf_free(pkbuf);
    return 0;
}
void Sctp_write_to_buffer(sctp_sock_t* sctp, pkbuf_t* pkbuf)
{
    if(!sctp)
        return;
    if(!pkbuf)
        return;

    // ogs_list_add(&sctp->write_queue, pkbuf);

    // if (!sctp->poll.write) {
    //     ogs_assert(sctp->sock);
    //     sctp->poll.write = ogs_pollset_add(ogs_app()->pollset,
    //         OGS_POLLOUT, sctp->sock->fd, sctp_write_callback, sctp);
    //     ogs_assert(sctp->poll.write);
    // }
}
void Sctp_flush_and_destroy(sctp_sock_t* sctp)
{
    // pkbuf_t *pkbuf = NULL, *next_pkbuf = NULL;

    if(!sctp)
        return;
    if(!sctp->addr)
        return;

    free(sctp->addr);

    if (sctp->type == SOCK_STREAM) 
    {
        // ogs_assert(sctp->poll.read);
        // ogs_pollset_remove(sctp->poll.read);

        // if (sctp->poll.write)
        //     ogs_pollset_remove(sctp->poll.write);

        Sock_destroy(sctp->sock);

        // ogs_list_for_each_safe(&sctp->write_queue, next_pkbuf, pkbuf) {
        //     ogs_list_remove(&sctp->write_queue, pkbuf);
        //     ogs_pkbuf_free(pkbuf);
        // }
    }
}

static int byte_nonzero(const uint8_t *u8, unsigned int offset, unsigned int u8_size)
{
    int j;

    for (j = offset; j < u8_size; j++) {
        if (u8[j] != 0)
            return j;
    }

    return -1;
}


static int sctp_sockopt_event_subscribe_size = 0;
static int sctp_sockopt_paddrparams_size = 0;

static int determine_sctp_sockopt_event_subscribe_size(void)
{
    uint8_t buf[256];
    socklen_t buf_len = sizeof(buf);
    int sd, rc;

    /* only do this once */
    if (sctp_sockopt_event_subscribe_size != 0)
        return 0;
    sd = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
    if (sd < 0)
        return sd;

    memset(buf, 0, sizeof(buf));
    rc = getsockopt(sd, IPPROTO_SCTP, SCTP_EVENTS, buf, &buf_len);
    closesocket(sd);
    if (rc < 0) {
        return rc;
    }
    sctp_sockopt_event_subscribe_size = buf_len;
    return 0;
}

static int sctp_setsockopt_event_subscribe_workaround(
        int fd, const struct sctp_event_subscribe *event_subscribe)
{
    const unsigned int compiletime_size = sizeof(*event_subscribe);
    int rc;

    if (determine_sctp_sockopt_event_subscribe_size() < 0) 
    {
        return -1;
    }
    if (compiletime_size == sctp_sockopt_event_subscribe_size) 
    {
        return setsockopt(fd, IPPROTO_SCTP, SCTP_EVENTS,
                event_subscribe, compiletime_size);
    }else if(compiletime_size < sctp_sockopt_event_subscribe_size) 
    {
        uint8_t buf[256];
        if(sctp_sockopt_event_subscribe_size > sizeof(buf))
        {
            return -1;
        }
        memcpy(buf, event_subscribe, compiletime_size);
        memset(buf + sizeof(*event_subscribe),
                0, sctp_sockopt_event_subscribe_size - compiletime_size);
        return setsockopt(fd, IPPROTO_SCTP, SCTP_EVENTS,
                buf, sctp_sockopt_event_subscribe_size);
    } 
    else
    {
        rc = byte_nonzero((const uint8_t *)event_subscribe,
                sctp_sockopt_event_subscribe_size, compiletime_size);
        if (rc >= 0) {
            return -1;
        }
        return setsockopt(fd, IPPROTO_SCTP, SCTP_EVENTS, event_subscribe,
                sctp_sockopt_event_subscribe_size);
    }
}

static int subscribe_to_events(sock_t *sock)
{
    struct sctp_event_subscribe event_subscribe;
    if(!sock)
        return -1;
    memset(&event_subscribe, 0, sizeof(event_subscribe));
    event_subscribe.sctp_data_io_event = 1;
    event_subscribe.sctp_association_event = 1;
    event_subscribe.sctp_send_failure_event = 1;
    event_subscribe.sctp_shutdown_event = 1;

    if (sctp_setsockopt_event_subscribe_workaround(sock->fd, &event_subscribe) < 0) 
        return -1;
    return 0;
}

static int determine_sctp_sockopt_paddrparams_size(void)
{
    uint8_t buf[256];
    socklen_t buf_len = sizeof(buf);
    int sd, rc;

    /* only do this once */
    if (sctp_sockopt_paddrparams_size != 0)
        return 0;

    sd = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
    if (sd < 0)
        return sd;

    memset(buf, 0, sizeof(buf));
    rc = getsockopt(sd, IPPROTO_SCTP, SCTP_PEER_ADDR_PARAMS, buf, &buf_len);
    closesocket(sd);
    if (rc < 0) 
        return rc;
    
    sctp_sockopt_paddrparams_size = buf_len;
    return 0;
}

static int sctp_setsockopt_paddrparams_workaround(
        int fd, const struct sctp_paddrparams *paddrparams)
{
    const unsigned int compiletime_size = sizeof(*paddrparams);
    int rc;

    if (determine_sctp_sockopt_paddrparams_size() < 0) 
        return -1;


    if (compiletime_size == sctp_sockopt_paddrparams_size) {
        /* no kernel workaround needed */
        return setsockopt(fd, IPPROTO_SCTP, SCTP_PEER_ADDR_PARAMS,
                paddrparams, compiletime_size);
    } else if (compiletime_size < sctp_sockopt_paddrparams_size) {
        /* we are using an older userspace with a more modern kernel
         * and hence need to pad the data */
        uint8_t buf[256];
        assert(sctp_sockopt_paddrparams_size <= sizeof(buf));

        memcpy(buf, paddrparams, compiletime_size);
        memset(buf + sizeof(*paddrparams),
                0, sctp_sockopt_paddrparams_size - compiletime_size);
        return setsockopt(fd, IPPROTO_SCTP, SCTP_PEER_ADDR_PARAMS,
                buf, sctp_sockopt_paddrparams_size);
    } else
    {
        rc = byte_nonzero((const uint8_t *)paddrparams,
                sctp_sockopt_paddrparams_size, compiletime_size);
        if (rc >= 0) 
            return 0;
        return setsockopt(fd, IPPROTO_SCTP, SCTP_PEER_ADDR_PARAMS, paddrparams,
                sctp_sockopt_paddrparams_size);
    }
}

static void sockopt_init(sockopt_t *option)
{
    if(!option)
        return;

    memset(option, 0, sizeof *option);

    option->sctp.spp_hbinterval = 5000;         /* 5 seconds */
    option->sctp.spp_sackdelay = 200;           /* 200 ms */
    option->sctp.srto_initial = 3000;           /* 3 seconds */
    option->sctp.srto_min = 1000;               /* 1 seconds */
    option->sctp.srto_max = 5000;               /* 5 seconds */
    option->sctp.sinit_num_ostreams = 30;
    option->sctp.sinit_max_instreams = 65535;
    option->sctp.sinit_max_attempts = 4;
    option->sctp.sinit_max_init_timeo = 8000;   /* 8 seconds */

    option->sctp_nodelay = 1;
    option->tcp_nodelay = 1;
}