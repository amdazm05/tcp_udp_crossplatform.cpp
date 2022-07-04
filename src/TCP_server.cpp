#include "TCP_server.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void TCP_server::set_address()
{
    this->server.sin_family = AF_INET;
    this->server.sin_port = htons(8080);
    this->server.sin_addr.s_addr = inet_addr("127.0.0.1");
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
        this->set_address();
        std::cout<<"Address set \n";
        if(server_so=socket(AF_INET,SOCK_STREAM,0) <0)
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
        if (bind(server_so, (struct sockaddr *)&server, sizeof(server)) <0)
            std::cout<<"Bind failed.\n";
    #endif
}

void handle_client(int client_socket)
{
    char buffer[BUFFER_SIZE_CLIENT];
    int receive_message_size;

    while (1)
    {
        if ((receive_message_size = recv(client_socket, buffer, BUFFER_SIZE_CLIENT, 0)) < 0)
            std::cout<<"Error on receive data.\n";
        buffer[receive_message_size]='\0';
        std::cout<<"[TCP Client]: "<< buffer<<"\n";
        if(receive_message_size)
        {
            break;
        }
    }
    #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
        closesocket(client_socket);
    #endif
}

void TCP_server::listen_server()
{
    if (listen(server_so, 10) < 0)
        std::cout<<"Listen failed.\n";
    while (1)
    {
        client_length = sizeof(client);
        std::cout<<client_length<<std::endl;
        if ((client_so = accept(server_so, (struct sockaddr *)&client, &client_length))<0)
        {   
            std::cout<<client_so<<std::endl;
            std::cout<<("Error on accept.\n");
            break;
        }
        
        printf("New connection accepted %s\n", inet_ntoa(client.sin_addr));
        handle_client(client_so);
    }
}