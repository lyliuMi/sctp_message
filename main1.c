#include "s1ap_msg_hdr.h"
#include "context.h"
#include "list.h"
#include "sctp.h"
#include "socket.h"
#include "s1ap_path.h"
#include "message.h"
#include "s1ap_build.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "nas_build.h"

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

// static sockaddr_t* get_dst_sockaddr_t()
// {
//     sockaddr_t* addr_t = (sockaddr_t*)malloc(sizeof(sockaddr_t));
//     addr_t->sin.sin_port = htons(36421);
//     addr_t->sin.sin_family = AF_INET;
//     inet_pton(AF_INET, "192.168.26.25", &addr_t->sin.sin_addr);
//     // inet_pton(AF_INET, "10.100.0.25", &addr_t->sin.sin_addr);

//     addr_t->hostname = (char*)malloc(10);
//     memcpy(addr_t->hostname, "lyl", 4);
//     addr_t->next = NULL;
//     return addr_t;
// }

#if 0
static void test2_main()
{
    int rv;
    sock_t* sctp;
    ssize_t size;
    uint32_t ppid;
    sctp_info_t sinfo;
    sockaddr_t* addr = get_sockaddr_t("10.100.0.25", 36421);
    
    //rv = ogs_getaddrinfo(&addr, AF_UNSPEC, NULL, TEST2_PORT, 0);

    sctp = Sctp_client(SOCK_SEQPACKET, addr, NULL);
    // int flags = fcntl(sctp->fd, F_GETFL, 0);  // 获取当前标志
    // fcntl(sctp->fd, F_SETFL, flags & ~O_NONBLOCK);  // 清除 O_NONBLOCK 标志

    pkbuf_config_t config;
    pkbuf_init();
    pkbuf_default_init(&config);
    pkbuf_default_create(&config);

    s1_setup_req_arg args;
    init_s1_setup_req_args(&args);

    s1_setup_res_arg res_args;
    init_s1_setup_res_args(&res_args);

    // pkbuf_t* ue_buf = pkbuf_alloc(NULL, OGS_MAX_SDU_LEN);
    // char data[46] = "asdasdasf";
    // ue_buf->data = data;
    // ue_buf->len = strlen(data);
    initial_uemessage_arg ue_args;
    init_initial_uemessage_arg(&ue_args);

    pkbuf_t* pkbuf = s1ap_build_s1_setup_request(&args);
    pkbuf_t* pkbuf2 = s1ap_build_s1_setup_response(&res_args);
    pkbuf_t* pkbuf4 = nas_build_attach_request();
    // pkbuf_t* pkbuf4 = nas_build_service_reject(OGS_NAS_EMM_CAUSE_SEMANTICALLY_INCORRECT_MESSAGE);

    pkbuf_t* pkbuf3 = s1ap_build_initial_uemessage(&ue_args, pkbuf4);
    

    // pkbuf_t* pkbuf = test_s1ap_build_s1_setup_request(S1AP_ENB_ID_PR_macroENB_ID, 0x345678);
    // char str[1024] = "hello, world";

    while(1)
    {
        size = Sctp_senddata(sctp, pkbuf, addr);
        if(size < 0)
        {
            perror("send s1_setup_req error:");
        }

        printf("send success: size = %ld\n", size);
        sleep(1);
        size = Sctp_senddata(sctp, pkbuf2, addr);
        if(size < 0)
        {
            perror("send s1_setup_res error:");
        }

        printf("send success: size = %ld\n", size);
        sleep(1);
        size = Sctp_senddata(sctp, pkbuf3, addr);
        if(size < 0)
        {
            perror("send initial_ue_msg error:");
        }

        printf("send success: size = %ld\n", size);
        sleep(1);
    }

    Sock_destroy(sctp);
}

int main(void)
{
    test2_main();

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
    // s1_setup_req_arg args;
    // init_s1_setup_req_args(&args);
    // pkbuf_t* pkbuf = s1ap_build_s1_setup_request(&args);

    addr = get_sockaddr_t("10.100.0.25", 36421);
    sctp = Sctp_server(SOCK_SEQPACKET, addr, NULL);
    int flags = fcntl(sctp->fd, F_GETFL, 0);  // 获取当前标志
    fcntl(sctp->fd, F_SETFL, flags & ~O_NONBLOCK);  // 清除 O_NONBLOCK 标志

    sockaddr_t from;
    sctp_info_t info;
    int sflags = 0;
    pkbuf_t* pkbuf = pkbuf_alloc(NULL, OGS_MAX_SDU_LEN);
    printf("server is listening \n");
    while(1)
    {
        size = Sctp_recvmsg(sctp, buf, sizeof(buf), &from, &info, &sflags);
        if(size < 0)
        {
            perror("recv error:");
            continue;
        }
        else
        {
            printf("port = %d, src = %s\n, size = %d \n", ntohs(from.sin.sin_port), inet_ntoa(from.sin.sin_addr), size);        
            if(size == 0)
                continue;
            
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

}

int main(void)
{
    test1_func();
    return 0;
}

#endif