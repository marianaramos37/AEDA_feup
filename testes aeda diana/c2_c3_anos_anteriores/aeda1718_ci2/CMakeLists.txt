cmake_minimum_required(VERSION 3.14)
project(aeda1718_ci2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1718_ci2
        Tests/Doctor.cpp
        Tests/Doctor.h
        Tests/Hospital.cpp
        Tests/Hospital.h
        Tests/Test.cpp)
target_link_libraries(aeda1718_ci2 gtest gtest_main)