#include "TCP_server.h"
#include <iostream>
void TCP_server::set_address()
{
    this->server.sin_family = AF_INET;
    this->server.sin_port = htons(8080);
    this->server.sin_addr.s_addr = inet_addr("127.0.0.1");
}

void TCP_server::socket_init()
{
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        std::cout<<"Failed WSAStartup.\n"; 
    this->set_address();
    if ((server_so = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
            std::cout<<"Failed socket.\n";

}

void TCP_server::bind_server()
{
     if (bind(server_so, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
        std::cout<<"Bind failed.\n";
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

    closesocket(client_socket);
}

void TCP_server::listen_server()
{
    if (listen(server_so, 100) < 0)
        std::cout<<"Listen failed.\n";
   while (1)
    {
        client_length = sizeof(client);

        if ((client_so = accept(server_so, (struct sockaddr *)&client, &client_length)) < 0)
            std::cout<<("Error on accept.\n");

        printf("New connection accepted %s\n", inet_ntoa(client.sin_addr));
        handle_client(client_so);
    }

    
}