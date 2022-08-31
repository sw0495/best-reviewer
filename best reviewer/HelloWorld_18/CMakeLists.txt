cmake_minimum_required(VERSION 3.8)
set(PROJECT HelloWorld)

project(${PROJECT})

# C++ settings
set(CMAKE_CXX_STANDARD 11)

enable_testing()
add_subdirectory(src)
add_subdirectory(test)

