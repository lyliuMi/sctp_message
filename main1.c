#include "s1ap_msg_hdr.h"
#include "context.h"
#include "list.h"
#include "s1ap_path.h"
#include "message.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

int running = 1;

void sig_handle(int sig)
{
    if(sig == SIGINT)
    {
        printf("signal execute;\n");
        running = 0;
    }
}

static sockaddr_t* get_sockaddr_t(const char* addr, uint16_t port)
{
    sockaddr_t* addr_t = (sockaddr_t*)malloc(sizeof(sockaddr_t));
    addr_t->sin.sin_port = htons(port);
    addr_t->sin.sin_family = AF_INET;
    inet_pton(AF_INET, addr, &addr_t->sin.sin_addr);

    // inet_pton(AF_INET, "10.100.0.25", &addr_t->sin.sin_addr);

    addr_t->hostname = (char*)malloc(10);
    memcpy(addr_t->hostname, "lyl", 4);
    addr_t->next = NULL;
    return addr_t;
}

#if 1
static void test2_main()
{
    int rv;
    sock_t* sctp;
    ssize_t size;
    uint32_t ppid;
    sctp_info_t sinfo;
    sockaddr_t* addr = get_sockaddr_t("192.168.177.129", 36421);
    
    //rv = ogs_getaddrinfo(&addr, AF_UNSPEC, NULL, TEST2_PORT, 0);

    sctp = Sctp_client(SOCK_SEQPACKET, addr, NULL);
    // int flags = fcntl(sctp->fd, F_GETFL, 0);  // 获取当前标志
    // fcntl(sctp->fd, F_SETFL, flags & ~O_NONBLOCK);  // 清除 O_NONBLOCK 标志

    while(running)
    {
        size = send_s1ap_s1_setup_req(sctp, addr);
        if(size < 0)
        {
            perror("send s1ap_s1_setup_req error:");
        }
        sleep(1);

        size = send_s1ap_initialueMsg(sctp, addr);
        if(size < 0)
        {
            perror("send s1ap_initialueMsg error:");
        }
        sleep(1);

        size = send_s1ap_s1_setup_res(sctp, addr);
        if(size < 0)
        {
            perror("send s1ap_s1_setup_res error:");
        }

        sleep(1);
        size = send_s1ap_initialContextSetupReq(sctp, addr);
        if(size < 0)
        {
            perror("send s1ap_initialContextSetupReq error:");
        }

        sleep(1);

        size = send_s1ap_initialContextSetupRes(sctp, addr);
        if(size < 0)
        {
            perror("send send_s1ap_initialContextSetupRes error:");
        }

        sleep(1);
        size = send_s1ap_uecontext_release_request(sctp, addr);
        if(size < 0)
        {
            perror("send send_s1ap_uecontext_release_request error:");
        }

        sleep(1);
        size = send_s1ap_uplink_nas_transport(sctp, addr);
        if(size < 0)
        {
            perror("send send_s1ap_uplink_nas_transport error:");
        }

        sleep(1);

    }
    Sock_destroy(sctp);
    free(addr);
}

int main(void)
{
    signal(SIGINT, sig_handle);
    pkbuf_config_t config;
    pkbuf_init();
    pkbuf_default_init(&config);
    pkbuf_default_create(&config);

    test2_main();
    pkbuf_default_destroy();
    pkbuf_final();
    return 0;
}
#else

static void test1_func()
{
    sock_t *sctp;
    sockaddr_t *addr;
    int size;
    int i;

    uint8_t buf[1024];
    pkbuf_config_t config;
    pkbuf_init();
    pkbuf_default_init(&config);
    pkbuf_default_create(&config);

    addr = get_sockaddr_t("192.168.177.129", 36421);
    sctp = Sctp_server(SOCK_SEQPACKET, addr, NULL);
    int flags = fcntl(sctp->fd, F_GETFL, 0);  // 获取当前标志
    fcntl(sctp->fd, F_SETFL, flags & ~O_NONBLOCK);  // 清除 O_NONBLOCK 标志

    sockaddr_t from;
    sctp_info_t info;
    int sflags = 0;
    pkbuf_t* pkbuf = pkbuf_alloc(NULL, OGS_MAX_SDU_LEN);
    printf("server is listening \n");
    while(running)
    {
        size = Sctp_recvmsg(sctp, buf, sizeof(buf), &from, &info, &sflags);
        if(size < 0)
        {
            perror("recv error:");
            break;
        }
        else
        {
            printf("port = %d, src = %s\n, size = %d \n", ntohs(from.sin.sin_port), inet_ntoa(from.sin.sin_addr), size);        
            printf("ppid = %d, stream_no = %d, inbound_streams = %d, outbound_streams = %d, sflags = %d\n",
                    info.ppid, info.stream_no, info.outbound_streams, info.inbound_streams, sflags);        
            
            for(i = 0; i < size; i++)
            {
                printf("%02x ", buf[i]);
            }
            printf("\n");

            s1ap_message_t s1ap;
            
            pkbuf->data = buf;
            pkbuf->len = size;
            if(s1ap_decode(&s1ap, pkbuf))
            {
                printf("decode fail\n");
            }

            s1ap_handle_s1_setup_request(&s1ap);
        }
    }
    pkbuf_free(pkbuf);

}

int main(void)
{
    signal(SIGINT, sig_handle);
    pkbuf_config_t config;
    pkbuf_init();
    pkbuf_default_init(&config);
    pkbuf_default_create(&config);

    test1_func();
    pkbuf_default_destroy();
    pkbuf_final();
    return 0;
}

#endif