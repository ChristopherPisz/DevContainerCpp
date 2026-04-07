cmake_minimum_required(VERSION 3.24 FATAL_ERROR)
cmake_policy(VERSION 3.24)
project(hello)
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

# Sub Directories
add_subdirectory(${CMAKE_SOURCE_DIR}/src/hellolib)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/helloapp)
add_subdirectory(${CMAKE_SOURCE_DIR}/test)