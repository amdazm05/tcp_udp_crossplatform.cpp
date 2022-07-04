#include "TCP_client.h"
#include <iostream>
#include <cstring>

void TCP_client::set_address()
{
    this->server.sin_family = AF_INET;
    this->server.sin_port = htons(8080);
    this->server.sin_addr.s_addr = inet_addr("127.0.0.1");
}

void TCP_client::socket_init()
{
     #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
           std::cout<<"WSAStartup has failed!";
    }
    #endif

    this-> set_address();
    this-> so = socket(AF_INET,SOCK_STREAM,0);
}

void TCP_client::connect_to_server()
{ 
    if (connect(so, (struct sockaddr *)&server, sizeof server) < 0)
            std::cout<<"Failed to connect \n";
}

void TCP_client::send_server(char * message)
{ 
    while(1) 
    {
        std::cout<<"Sending Message to [SERVER] \n";
        send(so, message, strlen(message) + 1, 0);
    }
}