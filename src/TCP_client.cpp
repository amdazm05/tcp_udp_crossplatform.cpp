#include "TCP_client.h"
#include <iostream>
#include <cstring>
#include <unistd.h>

void TCP_client::set_address(const char * serverAddress)
{
    this->server.sin_family = AF_INET;
    this->server.sin_port = htons(8080);
    this->server.sin_addr.s_addr = inet_addr(serverAddress); 
}

void TCP_client::socket_init()
{
     #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
           std::cout<<"WSAStartup has failed!";
    }
    #endif

    this-> so = socket(AF_INET,SOCK_STREAM,0);
    if(this->so ==0)
    {
        std::cout<<"Socket Failed to Initialised \n";
    }
}

void TCP_client::connect_to_server()
{ 
    if (connect(so, (struct sockaddr *)&server, sizeof(server)) < 0)
            std::cout<<"Failed to connect \n";
}

void TCP_client::send_server(const char * message)
{ 
    while(1) 
    {
        std::cout<<"Sending Message to [SERVER] \n";
        send(so, message, strlen(message) + 1, 0);
        // sleep(1);
    }
}