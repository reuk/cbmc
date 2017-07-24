cmake_minimum_required(VERSION 3.2)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

include(cotire)

add_subdirectory(src)

enable_testing()
add_subdirectory(unit)
