#include <UDP_client.h>

UDP_Client::UDP_Client()
{
    WSAStartup(MAKEWORD(2,2),&data);
}
UDP_Client::~UDP_Client()
{
    closesocket(socket_fd);
    WSACleanup();
}
void UDP_Client::set_address(const char * server_add, uint16_t server_add_port)
{

}
void UDP_Client::send_data(char * buffer)
{

}