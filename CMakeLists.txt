project(advcpp CXX)
cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
enable_testing()

add_subdirectory(templates)
