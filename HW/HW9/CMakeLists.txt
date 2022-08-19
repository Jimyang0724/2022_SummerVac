cmake_minimum_required(VERSION 3.15)
project(HW9)

add_subdirectory(POD)
add_executable(hw9 main.cpp)

target_link_libraries(hw9 PRIVATE POD_library)
target_compile_features(hw9 PRIVATE cxx_std_17)