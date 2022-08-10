cmake_minimum_required(VERSION 3.15)

add_library(src_5_1_library src_header/hw5_1.h hw5_1.cpp)
add_library(src_5_2_library src_header/hw5_2.h hw5_2.cpp)

target_include_directories(src_5_1_library PUBLIC src_header)
target_include_directories(src_5_2_library PUBLIC src_header)

target_compile_features(src_5_1_library PRIVATE cxx_std_17)
target_compile_features(src_5_2_library PRIVATE cxx_std_17)