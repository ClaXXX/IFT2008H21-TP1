cmake_minimum_required(VERSION 3.5)
project(TP1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wextra -Wall")

# Enable debugging
set(CMAKE_BUILD_TYPE Debug)

set(INCLUDE_DIR include)
set(SRC_DIR src)
include_directories(${INCLUDE_DIR})

set(SRCS
        ${SRC_DIR}/Labyrinthe.cpp
        ${SRC_DIR}/Piece.cpp
        ${SRC_DIR}/Porte.cpp
        ${SRC_DIR}/Principal.cpp)

add_executable(TP1 ${SRCS})

add_subdirectory(test)