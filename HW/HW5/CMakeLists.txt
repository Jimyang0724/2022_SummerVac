# cmake_minimum_required(VERSION 2.8)
project(HW5)
# include_directories(include)
file(GLOB SOURCES1 "./hw5_1.cpp")
file(GLOB SOURCES2 "./hw5_2.cpp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(hw5_1.exe ${SOURCES1})
add_executable(hw5_2.exe ${SOURCES1})