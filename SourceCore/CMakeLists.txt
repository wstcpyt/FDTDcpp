set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(sourceCore Source.cpp HardSource.cpp AdditiveSource.cpp RickerWaveletSource.cpp)
target_link_libraries(sourceCore fieldCore)
add_subdirectory(unit_test)