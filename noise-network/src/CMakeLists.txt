cmake_minimum_required(VERSION 3.16)

set(SOURCES SocketAddressFactory.cpp SocketAddressIPv4.cpp
            SocketAddressIPv6.cpp)

set(HEADERS SocketAddressFactory.h SocketAddressInterface.h SocketAddressIPv4.h
            SocketAddressIPv6.h)

add_library(noise_network_new ${SOURCES} ${HEADERS})
target_compile_features(noise_network_new PRIVATE cxx_std_20)

# Add compiler warnings
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
set_compiler_warnings(noise_network_new)

# sanitizer options if supported by compiler
include(${CMAKE_SOURCE_DIR}/cmake/Sanitizers.cmake)
enable_sanitizers(noise_network_new)
