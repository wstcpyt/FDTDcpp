set(BENCHMARK_DIR "../../cpplib/benchmark"
    CACHE PATH "The path to the Google Benchmark framework.")

add_subdirectory(${BENCHMARK_DIR} ${CMAKE_BINARY_DIR}/benchmark)

include_directories(SYSTEM ${BENCHMARK_DIR}/include)