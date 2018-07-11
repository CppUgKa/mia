cmake_minimum_required(VERSION 3.10)
project(mia)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 14)

add_executable(mia main.cpp)

find_package(asio REQUIRED)
target_include_directories(mia PUBLIC ${ASIO_INCLUDE_DIR})
add_definitions(-DASIO_HEADER_ONLY)