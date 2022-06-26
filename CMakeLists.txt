cmake_minimum_required(VERSION 3.0)
project(tcp_udp)
add_library(
    ${PROJECT_NAME}    
    static
    ${PROJECT_SOURCE_DIR}/src/TCP_client.cpp
    ${PROJECT_SOURCE_DIR}/src/TCP_server.cpp
)
target_include_directories(
    ${PROJECT_NAME} 
    public
    ${PROJECT_SOURCE_DIR}/include
)