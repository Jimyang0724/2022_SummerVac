cmake_minimum_required(VERSION 3.15)

add_library(engine_library engine_header/engine.h engine.cpp)

target_include_directories(engine_library PUBLIC engine_header)

target_compile_features(engine_library PRIVATE cxx_std_17)