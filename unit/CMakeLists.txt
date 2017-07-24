set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(unit
  unit_tests.cpp
  src/expr/require_expr.cpp
  src/ansi-c/c_to_expr.cpp
  analyses/does_remove_const/does_expr_lose_const.cpp
  analyses/does_remove_const/does_type_preserve_const_correctness.cpp
  analyses/does_remove_const/is_type_at_least_as_const_as.cpp
  catch_example.cpp
  )
target_include_directories(unit
  PUBLIC
  ${CBMC_BINARY_DIR}
  ${CBMC_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  )
target_link_libraries(unit ansi-c)
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
