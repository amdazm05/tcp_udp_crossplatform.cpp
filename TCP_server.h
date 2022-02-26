#ifndef _TCPH
#define _TCPH
//functions to have here
//steps to using the TCP header 
//
//If the program is a Linux header 

// #include <sys/socket.h> 
#include <winsock.h>
typedef int socklen;
class TCP_server
{
    public:
    TCP_server();
    TCP_server(/*Arguments*/);
    
    //Update the object below 
    void set_address(short   sin_family,
        u_short sin_port,
        struct in_addr sin_addr);

    //This will take input as the variable we the handle to be socketfd
    void socket_init();

    //To bind the changes 
    void bind_server();

    void listen_server();

    //Private variables 
    private:

    int domain;
    int type;
    struct sockaddr_in address;
    // Protocol 0 is IP
    int protocol;

    int sockfd;
};

#endif


/*
Some Learning NOTES 
-TCP almost always uses SOCK_STREAM and UDP uses SOCK_DGRAM.

-AF_INET is an address family that is used to designate the type of addresses
that your socket can communicate with (in this case, Internet Protocol v4 addresses)

-int sockfd = socket(domain, type, protocol)
//Example Domain is AF_NET
//type is SOCK_STREAM

SOL_SOCKET
Use this constant as the level argument to getsockopt or setsockopt to manipulate the socket-level options described in this section.

SO_REUSEADDR 
//This socket option tells the kernel that even if this port is busy (in the TIME_WAIT state), go ahead and reuse it anyway

*/
