cmake_minimum_required(VERSION 3.14)
project(aeda1617_ci2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1617_ci2
        Tests/AfterSalesService.cpp
        Tests/AfterSalesService.h
        Tests/Article.cpp
        Tests/Article.h
        Tests/Purchase.cpp
        Tests/Purchase.h
        Tests/Test.cpp)
target_link_libraries(aeda1617_ci2 gtest gtest_main)