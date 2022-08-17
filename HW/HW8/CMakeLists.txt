cmake_minimum_required(VERSION 3.15)
project(HW8)

add_subdirectory(Tuple_printer)
add_subdirectory(Inserter)
add_executable(hw8 main.cpp)

target_link_libraries(hw8 PRIVATE tuple_printer_library back_inserter_library)
target_compile_features(hw8 PRIVATE cxx_std_17)