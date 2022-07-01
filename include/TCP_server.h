#ifndef _TCPH
#define _TCPH
#include <winsock2.h>
#include <ws2tcpip.h>
#define BUFFER_SIZE_CLIENT 100
typedef int socklen;
class TCP_server
{
public:
    void set_address();
    void socket_init();
    void bind_server();

    void listen_server();

private:
    SOCKET server_so, client_so;
    WSADATA wsa;
    char *ip;
    int bytes_received;
    int client_length;
    unsigned short port;
    struct sockaddr_in server, client;
};

#endif
