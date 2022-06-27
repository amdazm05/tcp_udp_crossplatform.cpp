#include "TCP_client.h"
#include "TCP_client.cpp"
#include "TCP_server.h"
#include "TCP_server.cpp"
#include <iostream>
using namespace std;

int main()
{
    TCP_server Ahmed_server;
    Ahmed_server.socket_init();
    Ahmed_server.set_address();
    Ahmed_server.bind_server();
    Ahmed_server.listen_server();
    return 0;

}