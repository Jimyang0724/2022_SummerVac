# cmake_minimum_required(VERSION 2.8)
project(HW4)
# include_directories(include)
file(GLOB SOURCES "./*.cpp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(hw4.exe ${SOURCES})