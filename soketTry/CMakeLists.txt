cmake_minimum_required(VERSION 3.6)
project(soketTry)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp udp_client1.cpp udp_client2.cpp udp_server1.cpp.cpp udp_server2.cpp.cpp)
add_executable(soketTry ${SOURCE_FILES})