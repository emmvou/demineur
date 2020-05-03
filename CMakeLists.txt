cmake_minimum_required(VERSION 3.15)
project(demineur)

set(CMAKE_CXX_STANDARD 17)

add_executable(demineur main.cpp Cell.cpp Cell.h Grid.cpp Grid.h)