cmake_minimum_required(VERSION 2.6)
project(fsd)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME ON) 
find_package(Boost 1.57.0 COMPONENTS filesystem) 

include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
add_executable(fsd study.cpp extraTools.cpp printStudy.cpp main.cpp)
target_link_libraries(fsd ${Boost_LIBRARIES}) 

install(TARGETS fsd RUNTIME DESTINATION bin)
