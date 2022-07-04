#ifndef _TCPS
#define _TCPS

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    #include <winsock2.h>
    #include <ws2tcpip.h>
#endif

#if defined(unix) || defined(__unix__) || defined(__unix)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
#endif

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
    #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
        SOCKET server_so, client_so;
        WSADATA wsa;
        int client_length;
    #endif

    #if defined(unix) || defined(__unix__) || defined(__unix)
        int server_so,client_so;
        socklen_t client_length;
    #endif

    char *ip;
    int bytes_received;
    
    unsigned short port;
    struct sockaddr_in server, client;
};

#endif
