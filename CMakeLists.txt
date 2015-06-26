cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(FDTDcpp)
set(SOURCE_FILES main.cpp)
set(TEST_FILES FieldCore/unit_test/FieldTest.cpp FDTDCore/unit_test/FDTDTest.cpp SourceCore/unit_test/SourceUnitTest.cpp)
add_executable(FDTDcpp ${SOURCE_FILES} ${TEST_FILES})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

enable_testing()

include(gmock)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#add subdirectories
add_subdirectory(SourceCore)
add_subdirectory(FieldCore)
add_subdirectory(FDTDCore)
add_subdirectory(VisualCore)


#link libraries
target_link_libraries(FDTDcpp sourceCore)
target_link_libraries(FDTDcpp fieldCore)
target_link_libraries(FDTDcpp fdtdCore)
target_link_libraries(FDTDcpp gmock)
target_link_libraries(FDTDcpp gtest)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")