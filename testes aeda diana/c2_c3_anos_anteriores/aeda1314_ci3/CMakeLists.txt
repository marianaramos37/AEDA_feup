cmake_minimum_required(VERSION 3.14)
project(aeda1314_ci3)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1314_ci3
        Tests/ClubeVideo.cpp
        Tests/ClubeVideo.h
        Tests/Test.cpp)

target_link_libraries(aeda1314_ci3 gtest gtest_main)