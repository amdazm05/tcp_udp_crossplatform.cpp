#ifndef _TCPC
#define _TCPC

#define PORT 8080
#define BUFFER_SIZE 200
#include <winsock2.h>
#include <ws2tcpip.h>

class TCP_client
{
public:
    void socket_init();
    void set_address();
    void connect_to_server();
    void send_server(char *message);

private:
    char buffer[BUFFER_SIZE];
    char *serverip;
    int type;
    struct sockaddr_in server;
    int bytes_received;
    int protocol;
    SOCKET so;
    WSADATA wsa;
};

#endif