configure_file(tests/testcase0.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase0.txt COPYONLY)
configure_file(tests/testcase1.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase1.txt COPYONLY)
configure_file(tests/testcase2.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase2.txt COPYONLY)

add_executable(Encryption src/main.cpp)

set_property(TARGET Encryption PROPERTY FOLDER "hackerrank/Algorithms/Implementation")