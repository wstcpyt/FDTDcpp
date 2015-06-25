set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(fdtdCore FDTD.cpp)
add_subdirectory(unit_test)
target_link_libraries(fdtdCore fieldCore)