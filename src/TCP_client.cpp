#include "TCP_client.h"

void TCP_client::set_address(short sin_family, u_short sin_port, struct in_addr sin_addr)
{
    this->serv_addr.sin_family = sin_family;
    this->serv_addr.sin_port = htons(sin_port);
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
    // InetPton(AF_INET, "127.0.0.1", &(this->serv_addr.sin_addr));
    connect(sockfd, (struct sockaddr *)&(this->serv_addr), sizeof((this->serv_addr)));

    
}

void TCP_client::send_server()
{
    // char *hello="Hellow Socket";
    //  send(sockfd , hello , strlen(hello) , 0 );
}