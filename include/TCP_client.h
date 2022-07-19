#ifndef _TCPC
#define _TCPC

#define PORT 8080
#define BUFFER_SIZE 200

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    #include <winsock2.h>
    #include <ws2tcpip.h>
#endif

#if defined(unix) || defined(__unix__) || defined(__unix)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <sys/types.h>
    #include <arpa/inet.h>
#endif



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
    #if defined(unix) || defined(__unix__) || defined(__unix)
        int so;
    #endif

    #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
        SOCKET so;
        WSADATA wsa;
    #endif
        
};

#endif