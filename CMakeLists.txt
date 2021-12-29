cmake_minimum_required(VERSION 3.8)

set(This DynProgProject)
project(${This} C CXX)
set(CMAKE_CXX_STANDARD 17)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
enable_testing()
add_subdirectory(googletest)

set(Headers
DynamicProg_Problems.hh
)

set(Sources
DynamicProg_Problems.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)

