cmake_minimum_required(VERSION 3.16)

enable_testing()

include_directories(../src/)

add_executable(test_noise_network_new test.cpp)
target_compile_features(test_noise_network_new PRIVATE cxx_std_20)

# Add compiler warnings
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
set_compiler_warnings(test_noise_network_new)

# sanitizer options if supported by compiler
include(${CMAKE_SOURCE_DIR}/cmake/Sanitizers.cmake)
enable_sanitizers(test_noise_network_new)

target_link_libraries(test_noise_network_new PRIVATE noise_network_new)
