#include <UDP_server.h>
#include <iostream>
UDP_Server::UDP_Server()
{
    WSAStartup(MAKEWORD(2,2),&data);
    set_address(0);
    bind_server();

}

UDP_Server::UDP_Server(uint16_t port)
{
    WSAStartup(MAKEWORD(2,2),&data);
    set_address(port);
    bind_server();
}


UDP_Server::~UDP_Server()
{
    closesocket(socket_fd);
    WSACleanup();
}

void UDP_Server::bind_server()
{
    this-> socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    bind(this->socket_fd, (sockaddr *)&local, sizeof(local));
}

void UDP_Server::set_address(uint16_t port)
{
    local.sin_family=AF_INET;//Set a ipv4 socket 
    inet_pton(AF_INET,INADDR_ANY,&local.sin_addr.s_addr);
    local.sin_port = htons(port);
}

void UDP_Server::server_up()
{           
    int local_length=sizeof(destination);
    const char * message = "Acknowledged";
    while(1)
    {
        recvfrom(socket_fd,buffer,BUFFERSIZE,0,(sockaddr *)&destination,&local_length);
        std::cout<<buffer<<std::endl;
        sendto(socket_fd, message, strlen(message), 0, (sockaddr*)&destination, sizeof(sockaddr_in));

    }       
}