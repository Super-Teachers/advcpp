project(advcpp CXX)
cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

add_definitions(-std=c++17)

enable_testing()

include(GoogleTest)
add_subdirectory(googletest/googletest)
add_subdirectory(templates)
