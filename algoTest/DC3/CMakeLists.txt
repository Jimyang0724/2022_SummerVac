# cmake_minimum_required(VERSION 2.8)
project(DC3)
# include_directories(include)
file(GLOB SOURCES "./*.cpp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(DC3_Test.exe ${SOURCES})
