#include "TCP_server.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void TCP_server::set_address()
{
    this->server.sin_family = AF_INET;
    this->server.sin_port = htons(8080);
    this->server.sin_addr.s_addr = INADDR_ANY;
}

void TCP_server::socket_init()
{
    #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
        if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
            std::cout<<"Failed WSAStartup.\n"; 
        this->set_address();
        if ((server_so = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
            std::cout<<"Failed socket.\n";
    #endif

    #if defined(unix) || defined(__unix__) || defined(__unix)
        std::cout<<"Address set \n";
        this->set_address();
        this->server_so=socket(AF_INET,SOCK_STREAM,0);
        if(this->server_so<0)
            std::cout<<"Failed socket. \n";
    #endif
}

void TCP_server::bind_server()
{
    #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
        if (bind(server_so, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
        std::cout<<"Bind failed.\n";
    #endif
    #if defined(unix) || defined(__unix__) || defined(__unix)
        if (bind(this->server_so, (struct sockaddr *)&(server), sizeof(server)) <0)
            std::cout<<"Bind failed.\n";
    #endif
}

void handle_client(int client_socket)
{
    //TODO Revise these requirements 
}

void TCP_server::listen_server()
{
    char buffer[BUFFER_SIZE_CLIENT];

    this->addr_length=sizeof(server);
    if (listen(server_so, 3) < 0) 
    {
        std::cerr<<"Listen:" <<errno; 
        exit(EXIT_FAILURE); 
    } 
    if ((client_so = accept(this->server_so, (struct sockaddr *)&server,  
                       (socklen_t*)&(this->addr_length)))<0) 
        {
            std::cerr<<"Accept:" <<errno; 
            exit(EXIT_FAILURE); 
        }

    #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
        recv(this->client_so,buffer,BUFFER_SIZE_CLIENT,0);
        std::cout<<"Recieved data : "<< buffer;
        closesocket(client_so);
    #endif

    #if defined(unix) || defined(__unix__) || defined(__unix)

        read( client_so , buffer, 1024); 
        std::cout<<"Recieved data : "<< buffer;

         
    #endif
    
 
}