cmake_minimum_required(VERSION 2.6)
project(fsd)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
add_executable(fsd study.cpp extraTools.cpp printStudy.cpp main.cpp)

install(TARGETS fsd RUNTIME DESTINATION bin)
