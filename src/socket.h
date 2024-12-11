#ifndef _SOCKET_H
#define _SOCKET_H

#include <netinet/in.h>
#include <netinet/sctp.h>
#include <arpa/inet.h>

typedef struct sockaddr_s
{
    union
    {
        struct sockaddr_storage ss;
        struct sockaddr_in sin;
        struct sockaddr_in6 sin6;
        struct sockaddr sa;
    };
    char *hostname;
    char *fqdn;
    struct sockaddr_s *next;
}sockaddr_t;

typedef struct sock_s
{
    int family;
    int fd;
    sockaddr_t local_addr;
    sockaddr_t remote_addr;
}sock_t;

sock_t* Sock_create(void);
void Sock_destroy(sock_t* sock);

sock_t* Sock_socket(int family, int type, int protocol);
int Sock_bind(sock_t* sock, sockaddr_t* addr);
int Sock_connect(sock_t* sock, sockaddr_t* addr);

int Sock_listen(sock_t* sock);
sock_t* Sock_accept(sock_t* sock);

ssize_t Write(int fd, const void* buf, size_t len);
ssize_t Read(int fd, void* buf, size_t len);

ssize_t Send(int fd, const void* buf, size_t len, int flags);
ssize_t Sendto(int fd,
        const void* buf, size_t len, int flags, const sockaddr_t* to);
ssize_t Recv(int fd, void* buf, size_t len, int flags);
ssize_t Recvfrom(int fd, void* buf, size_t len, int flags, sockaddr_t* from);

int closesocket(int fd);

#endif