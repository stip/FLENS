cmake_minimum_required(VERSION 3.13)

project(FLENS C CXX)

add_subdirectory(cxxblas)
add_subdirectory(cxxlapack)
add_subdirectory(cxxstd)
add_subdirectory(flens)
add_subdirectory(external)

add_library(libflens INTERFACE)
target_include_directories(libflens INTERFACE .)