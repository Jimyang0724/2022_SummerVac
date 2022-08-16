cmake_minimum_required(VERSION 3.15)
project(hw7)

add_subdirectory(question_7a)
add_subdirectory(question_7b)

add_executable(hw7 main.cpp)
target_link_libraries(hw7 PRIVATE question_7a_library question_7b_library)

target_compile_features(hw7 PRIVATE cxx_std_17)