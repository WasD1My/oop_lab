cmake_minimum_required(VERSION 3.25)
project(oop_lab1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(../oop_lab1_old/googletest)

add_executable(oop_lab1
        main.cpp item.h item_test.h container.h container_test.h)
