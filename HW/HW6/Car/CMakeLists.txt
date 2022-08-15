cmake_minimum_required(VERSION 3.15)

add_library(car_library car_header/car.h car.cpp)

target_include_directories(car_library PUBLIC car_header)
target_link_libraries(car_library PUBLIC engine_library)

target_compile_features(car_library PRIVATE cxx_std_17)