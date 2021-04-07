cmake_minimum_required(VERSION 3.17)

add_library(noise_network_new library.cpp library.h)
target_compile_features(noise_network_new PRIVATE cxx_std_20)

# Add compiler warnings
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
set_compiler_warnings(noise_network_new)

include(${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)
