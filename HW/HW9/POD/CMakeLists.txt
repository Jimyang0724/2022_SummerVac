cmake_minimum_required(VERSION 3.15)

add_library(POD_library trade_date_header/trade_date.h trade_date.cpp)

target_include_directories(POD_library PUBLIC trade_date_header)
target_compile_features(POD_library PRIVATE cxx_std_17)
