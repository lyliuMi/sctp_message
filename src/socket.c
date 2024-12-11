#include "socket.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

sock_t* Sock_create(void)
{
    sock_t* sock = NULL;
    sock = (sock_t*)malloc(sizeof(sock_t));
    if(!sock)
    {
        return NULL;
    }

    return sock;
}
void Sock_destroy(sock_t* sock)
{
    if(!sock) 
        return;
    if(sock->fd != -1)
    {
        closesocket(sock->fd);
    }

    sock->fd = -1;
    free(sock);
}

sock_t* Sock_socket(int family, int type, int protocol)
{   
    sock_t* sock = Sock_create();
    if(!sock)
        return NULL;
    sock->family = family;
    sock->fd = socket(sock->family, type, protocol);
    if (sock->fd < 0) {
        Sock_destroy(sock);
        
        return NULL;
    }
    return sock;
}
int Sock_bind(sock_t* sock, sockaddr_t* addr)
{   
    char buf[46];
    socklen_t addrlen;

    if(!sock)
        return -1;
    if(!addr)
        return -1;

    switch(addr->sa.sa_family)
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

    if (bind(sock->fd, &addr->sa, addrlen) != 0) {
        fprintf(stderr,
                "socket bind(%d) [%s]:%d failed",
                addr->sa.sa_family, inet_ntop(sock->family, &addr->sin.sin_addr, buf, addrlen), addr->sin.sin_port);
        return -1;
    }

    memcpy(&sock->local_addr, addr, sizeof(sock->local_addr));
    return 0;
}
int Sock_connect(sock_t* sock, sockaddr_t* addr)
{
    socklen_t addrlen;

    if(!sock)
        return -1;
    if(!addr)
        return -1;

    switch(addr->sa.sa_family)
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
    if (connect(sock->fd, &addr->sa, addrlen) != 0) {
        return -1;
    }

    memcpy(&sock->remote_addr, addr, sizeof(sock->remote_addr));
    return 0;
}

int Sock_listen(sock_t* sock)
{
    int rc;
    if(!sock)
        return -1;

    rc = listen(sock->fd, 5);
    if (rc < 0) {
        return -1;
    }

    return 0;
}
sock_t* Sock_accept(sock_t* sock)
{
    sock_t *new_sock = NULL;

    int new_fd = -1;
    sockaddr_t addr;
    socklen_t addrlen;

    if(!sock)
        return NULL;

    memset(&addr, 0, sizeof(addr));
    addrlen = sizeof(addr.ss);

    new_fd = accept(sock->fd, &addr.sa, &addrlen);
    if (new_fd < 0) {
        return NULL;
    }

    new_sock = Sock_create();
    if(!new_sock)
        return NULL;

    new_sock->family = sock->family;
    new_sock->fd = new_fd;

    memcpy(&new_sock->remote_addr, &addr, sizeof(new_sock->remote_addr));

    return new_sock;
}

ssize_t Write(int fd, const void* buf, size_t len)
{
    if(fd == -1)
        return -1;
    return write(fd, buf, len);
}
ssize_t Read(int fd, void* buf, size_t len)
{
    if(fd == -1)
        return -1;
    return read(fd, buf, len);    
}

ssize_t Send(int fd, const void* buf, size_t len, int flags)
{
    if(fd == -1)
        return -1;
    return send(fd, buf, len, flags);    
}
ssize_t Sendto(int fd, const void* buf, size_t len, int flags, const sockaddr_t* to)
{
    if(fd == -1 || !to)
        return -1;
    socklen_t addrlen;

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

    return sendto(fd, buf, len, flags, &to->sa, addrlen);
}
ssize_t Recv(int fd, void* buf, size_t len, int flags)
{
    if(fd == -1)
        return -1;
    return recv(fd, buf, len, flags);
}
ssize_t Recvfrom(int fd, void* buf, size_t len, int flags, sockaddr_t* from)
{
    if(fd == -1 || !from)
        return -1;
    socklen_t addrlen;
    switch(from->sa.sa_family)
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

    return recvfrom(fd, buf, len, flags, &from->sa, &addrlen);
}

int closesocket(int fd)
{
    int r;
    r = close(fd);
    if (r != 0) {
        return -1;
    }
    return 0;
}