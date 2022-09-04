#include <UDP_client.h>

#define DEFAULT_ADR  "127.0.0.1"
#define DEFAULT_PORT 8080

UDP_Client::UDP_Client()
{
    WSAStartup(MAKEWORD(2,2),&data);
    this-> socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    set_address(DEFAULT_ADR,DEFAULT_PORT);
}
UDP_Client::~UDP_Client()
{
    closesocket(socket_fd);
    WSACleanup();
}

void UDP_Client::set_address(const char * server_add, uint16_t server_add_port)
{
    server_.sin_family=AF_INET;
    inet_pton(AF_INET,(PCSTR)server_add,&server_.sin_addr.S_un.S_addr);
    server_.sin_port=htons(server_add_port);
}
void UDP_Client::send_data(char * buffer)
{
    sendto(socket_fd,buffer,sizeof(buffer),0,(sockaddr*)&server_,sizeof(server_));
}