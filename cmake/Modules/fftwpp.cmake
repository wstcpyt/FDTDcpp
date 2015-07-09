set(FFTWPP_DIR "../../cpplib/fftw++-1.13"
    CACHE PATH "The path to the FFTWPP_DIR framework.")
add_subdirectory(${FFTWPP_DIR} ${CMAKE_BINARY_DIR}/fftwpp)
include_directories(SYSTEM ${FFTWPP_DIR})