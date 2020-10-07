cmake_minimum_required(VERSION 3.14)
project(teste1718_pratica)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(teste1718_pratica
        BST.h
        Expertize.cpp
        Expertize.h
        FEUPConsulting.cpp
        FEUPConsulting.h
        Project.cpp
        Project.h
        Student.cpp
        Student.h
        Test.cpp)
