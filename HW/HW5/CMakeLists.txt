cmake_minimum_required(VERSION 3.15)
project(HW5)

add_subdirectory(src)
add_executable(hw5 main.cpp)

target_link_libraries(hw5 PRIVATE src_5_1_library src_5_2_library)

target_compile_features(hw5 PRIVATE cxx_std_17)