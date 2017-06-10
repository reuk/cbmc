file(GLOB_RECURSE sources "*.cpp")
add_library(util ${sources})

generic_includes(util)

target_link_libraries(util big-int)
