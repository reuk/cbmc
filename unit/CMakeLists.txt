set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(unit
  unit_tests.cpp
  catch_example.cpp
  analyses/call_graph.cpp
  java_bytecode/java_bytecode_convert_class/convert_abstract_class.cpp
  solvers/refinement/string_constraint_generator_valueof/is_digit_with_radix.cpp
  solvers/refinement/string_constraint_generator_valueof/get_numeric_value_from_character.cpp
  )
target_include_directories(unit
  PUBLIC
  ${CBMC_BINARY_DIR}
  ${CBMC_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  )
target_link_libraries(unit ansi-c java_bytecode solvers)
add_test(unit unit)

add_executable(miniBDD miniBDD.cpp)
target_include_directories(miniBDD
  PUBLIC
  ${CBMC_BINARY_DIR}
  ${CBMC_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  )
target_link_libraries(miniBDD solvers ansi-c)
add_test(miniBDD miniBDD)

add_executable(string_utils string_utils.cpp)
target_include_directories(string_utils
  PUBLIC
  ${CBMC_BINARY_DIR}
  ${CBMC_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  )
target_link_libraries(string_utils solvers ansi-c)
add_test(string_utils string_utils)

add_executable(sharing_node sharing_node.cpp)
target_include_directories(sharing_node
  PUBLIC
  ${CBMC_BINARY_DIR}
  ${CBMC_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  )
add_test(sharing_node sharing_node)

install(TARGETS unit miniBDD string_utils sharing_node DESTINATION bin)
