cmake_minimum_required(VERSION 3.5)
project(ExploringAlgorithms)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
                TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES gtest/[1.11] benchmark/[>1.4]
                      GENERATORS cmake_find_package)
                      
conan_cmake_autodetect(settings)
conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})

option(WITH_SORTING "Will build all sorting algorithms" ON)
option(BUILD_TESTS "Will build the tests verifying your result" ON)
option(BUILD_BENCHMARK "This will enable the performance tests using google benchmark" ON)

if(WITH_SORTING)
    add_subdirectory(src/sorting)
endif()