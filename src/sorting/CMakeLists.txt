add_library(sorting INTERFACE)
add_library(algorithms::sorting ALIAS sorting)

target_sources(sorting INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/quicksort.hpp    
)

target_compile_options(sorting INTERFACE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Werror -pedantic-errors -Wextra -Wconversion -Wsign-conversion -Wno-gnu-zero-variadic-macro-arguments>
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4>
)

target_compile_features(sorting INTERFACE cxx_std_20)


if(BUILD_TESTS)
    find_package(GTest REQUIRED)

    add_executable(sorting_tests)
    
    target_sources(sorting_tests PRIVATE 
        tests.cpp)

    target_link_libraries(sorting_tests PRIVATE
        algorithms::sorting
        GTest::GTest
        GTest::gtest_main
    )

    target_compile_options(sorting_tests PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
            -Wno-gnu-zero-variadic-macro-arguments>
    )

    include(GoogleTest)
    enable_testing()
    gtest_discover_tests(sorting_tests)
endif()


if(BUILD_BENCHMARK)
    find_package(benchmark REQUIRED)
    # Requires PThreads on Linux
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)

    add_executable(sorting_benchmarks)

    target_sources(sorting_benchmarks PRIVATE 
        benchmarks.cpp)

    target_link_libraries(sorting_benchmarks PRIVATE
        algorithms::sorting
        benchmark::benchmark
        Threads::Threads
    )

    add_custom_target(NAME sorting_benchmarks
        COMMAND sorting_benchmarks
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()
