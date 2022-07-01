#include "TCP_client.h"
#include <iostream>
void TCP_client::set_address()
{
    this->address.sin_family = AF_INET;
    this->address.sin_port = htons(8080);
    this->address.sin_addr.s_addr = inet_addr("127.0.0.1");
}

void TCP_client::socket_init()
{
    //Definition 
    //int sockfd = socket(domain, type, protocol)
    /*
    sockfd: socket descriptor, an integer (like a file-handle)
    
    domain: integer, communication domain e.g., AF_INET (IPv4 protocol) , AF_INET6 (IPv6 protocol)
    
    type: communication type
    
    SOCK_STREAM: TCP(reliable, connection oriented)
    
    SOCK_DGRAM: UDP(unreliable, connectionless)
    
    protocol: Protocol value for Internet Protocol(IP), which is 0. 
    This is the same number which appears on protocol field in the IP header of a packet.(man protocols for more deta
    */
    this->sockfd = socket(AF_INET,SOCK_STREAM,0);

}

void TCP_client::connect_to_server()
{
    std::cout<<address.sin_family<<address.sin_port<<std::endl;  
    if(connect(sockfd, (struct sockaddr *)&(this->address), sizeof((this->address))< 0))
        std::cout<<"Error Connecting "<<std::endl;  
}

void TCP_client::send_server()
{
    char *hello="Hellow Socket";
    send(sockfd , hello , strlen(hello) , 0 );
}