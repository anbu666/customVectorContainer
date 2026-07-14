cmake_minimum_required(VERSION 3.10)

project(LinearAlgebraVector VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(VectorApp src/main.cpp)

target_include_directories(VectorApp PRIVATE include)
