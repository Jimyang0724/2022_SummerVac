cmake_minimum_required(VERSION 3.15)
project(HW6)

add_subdirectory(Engine)
add_subdirectory(Car)
add_executable(hw6 main.cpp)

target_link_libraries(hw6 PRIVATE engine_library car_library)

target_compile_features(hw6 PRIVATE cxx_std_17)