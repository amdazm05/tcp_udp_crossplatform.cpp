cmake_minimum_required(VERSION 3.0)
project(tcp_udp)
add_library(
    ${PROJECT_NAME}    
    STATIC
    ${PROJECT_SOURCE_DIR}/src/TCP_client.cpp
    ${PROJECT_SOURCE_DIR}/src/TCP_server.cpp
)
target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(tcp_udp PUBLIC wsock32 )
