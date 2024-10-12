cmake_minimum_required(VERSION 3.22)
project(Laboratory_of_programming)

set(CMAKE_CXX_STANDARD 17)

add_executable(Laboratory_of_programming main.cpp)
add_subdirectory(Test)
set(SOURCE_FILES Date.cpp Date.h ToDo.h ToDo.cpp TodoList.cpp TodoList.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(Laboratory_of_programming core)

