#ifndef _UDPS
#define _UDPS

#include <stdint.h>

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

#define BUFFERSIZE 512
class UDP_Server 
{
   public:
        UDP_Server();
        UDP_Server(uint16_t port); 
        ~UDP_Server();
        void server_up();
    
   private:
        void set_address(uint16_t port);
        void bind_server();
        char buffer[BUFFERSIZE]={};
        WSAData data;
        SOCKADDR socketaddress;
        sockaddr_in local;
        sockaddr_in destination;
        SOCKET socket_fd;
};