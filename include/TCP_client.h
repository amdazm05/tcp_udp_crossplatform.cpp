#ifndef _TCPC
#define _TCPC
//functions to have here
//steps to using the TCP header 
//
//If the program is a Linux header //TODO 
#define PORT 8080 
// #include <sys/socket.h> 
#include <winsock2.h>
#include <ws2tcpip.h>
// #pragma comment(lib, "ws2_32.lib")

typedef int socklen;
class TCP_client
{
    public:
    // TCP_client(/*Arguments*/);
    
    //Update the object below 
    void set_address(short   sin_family,
        u_short sin_port,
        struct in_addr sin_addr);

    //This will take input as the variable we the handle to be socketfd
    void socket_init();
    void connect_to_server();
    void send_server();

    //Private variables 
    private:
    char buffer[1024];
    int domain;
    int type;
    struct sockaddr_in address; //Check if needed else discards
    struct sockaddr_in serv_addr; 
    // Protocol 0 is IP
    int protocol;

    int sockfd;
};

//Program flow for client side 
// 1-socket(); 
// 2-inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
// 3-connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)); 
// 4-send(sock , hello , strlen(hello) , 0 ); 


#endif