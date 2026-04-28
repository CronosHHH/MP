cmake_minimum_required(VERSION 3.12)
project(Tarjetas)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")

include_directories(include)

set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES src/main.cpp)

add_executable(${BINARY} ${SOURCES})