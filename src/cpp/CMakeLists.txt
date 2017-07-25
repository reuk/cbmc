file(GLOB_RECURSE sources "*.cpp")
file(GLOB_RECURSE headers "*.h")
add_library(cpp ${sources} ${headers}) 
cotire(cpp)

generic_includes(cpp)

target_link_libraries(cpp util ansi-c)
