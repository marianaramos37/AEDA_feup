cmake_minimum_required(VERSION 3.14)
project(aeda1516_ci3)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1516_ci3
        Tests/Dish.cpp
        Tests/Dish.h
        Tests/Restaurant.cpp
        Tests/Restaurant.h
        Tests/Table.cpp
        Tests/Table.h
        Tests/Test.cpp)
target_link_libraries(aeda1516_ci3 gtest gtest_main)