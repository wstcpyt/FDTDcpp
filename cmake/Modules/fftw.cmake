set(FFTW_DIR "../../cpplib/fftw-3.3.4"
    CACHE PATH "The path to the FFTW_DIR framework.")
add_subdirectory(${FFTW_DIR} ${CMAKE_BINARY_DIR}/fftw)
include_directories(SYSTEM ${FFTW_DIR}/api)