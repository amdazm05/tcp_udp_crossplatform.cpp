#ifndef _UDPC
#define _UDPC

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


class UDP_Client 
{
   public:
        UDP_Client();
        ~UDP_Client();
        void set_address(const char * server_add, uint16_t server_add_port);
        void send_data(char * buffer);
    
   private:
        WSAData data;
        SOCKADDR socketaddress;
        sockaddr_in server_;
        SOCKET socket_fd;
};
#endif