#include "TCP_server.h"

void TCP_server::set_address()
{
    this->address.sin_family = AF_INET;
    this->address.sin_port = htons(8080);
    this->address.sin_addr.s_addr =INADDR_ANY ;
}

void TCP_server::socket_init()
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

void TCP_server::bind_server()
{
    bind((this->sockfd), (struct sockaddr *)&(this->address), sizeof(this->address));
}

void TCP_server::listen_server()
{
    // int listen(int sockfd, int backlog);
// It puts the server socket in a passive mode, where it waits for the client 
// to approach the server to make a connection. 
// The backlog, defines the maximum length to which the queue of pending connections for sockfd may grow.
//  If a connection request arrives when the queue is full, 
//  the client may receive an error with an indication of ECONNREFUSED
    listen((this->sockfd), 3);
}