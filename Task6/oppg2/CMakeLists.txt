cmake_minimum_required(VERSION 3.13)
project(oppg2)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra -Wno-unused-parameter")


find_package(Boost 1.55.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})



include_directories(${Boost_INCLUDE_DIR})

add_executable(oppg2 main.cpp)
target_link_libraries(oppg2 ${Boost_LIBRARIES})
