cmake_minimum_required(VERSION 3.2)

include(GNUInstallDirs)

add_subdirectory(src)

enable_testing()
add_subdirectory(unit)
