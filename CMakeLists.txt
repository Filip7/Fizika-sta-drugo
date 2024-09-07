cmake_minimum_required(VERSION 3.30)
project(fsd)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
add_executable(fsd study.cpp extraTools.cpp printStudy.cpp dfPath.cpp  main.cpp)

install(TARGETS fsd RUNTIME DESTINATION bin)
