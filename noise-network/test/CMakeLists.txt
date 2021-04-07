cmake_minimum_required(VERSION 3.17)

include_directories(../src/)

set(test_noise_network_sources library_test.h library_test.cpp)

add_executable(test_noise_network_new library_test.cpp)
target_compile_features(test_noise_network_new PRIVATE cxx_std_20)

# Add compiler warnings
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
set_compiler_warnings(test_noise_network_new)

target_link_libraries(test_noise_network_new PRIVATE noise_network_new)
