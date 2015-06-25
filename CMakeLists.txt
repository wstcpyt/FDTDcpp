cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(FDTDcpp)
set(SOURCE_FILES main.cpp)
add_executable(FDTDcpp ${SOURCE_FILES})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

enable_testing()

include(gmock)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#add subdirectories
add_subdirectory(SourceCore)
add_subdirectory(FieldCore)
add_subdirectory(FDTDCore)


#link libraries
target_link_libraries(FDTDcpp sourceCore)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")