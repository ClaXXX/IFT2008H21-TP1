cmake_minimum_required(VERSION 3.5)
project(TP1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wextra -Wall")

# Enable debugging
set(CMAKE_BUILD_TYPE Debug)

set(SRC_DIR .)
include_directories(${SRC_DIR})

set(SRCS
        ${SRC_DIR}/Labyrinthe.cpp
        ${SRC_DIR}/Piece.cpp
        ${SRC_DIR}/Porte.cpp
        ${SRC_DIR}/Principal.cpp)

add_executable(TP1 ${SRCS})