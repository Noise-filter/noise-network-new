cmake_minimum_required(VERSION 3.16)
project(
        noise_network_new
        VERSION 0.1
        DESCRIPTION "Networking library"
        LANGUAGES CXX)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(
            STATUS
            "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(
            DOWNLOAD
            "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(REQUIRES Catch2/2.6.0@catchorg/stable BASIC_SETUP CMAKE_TARGETS)

include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

# enable cache system
include(cmake/Cache.cmake)

include(cmake/StaticAnalyzers.cmake)

add_subdirectory(noise-network)
