configure_file(tests/testcase0.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase0.txt COPYONLY)
configure_file(tests/testcase1.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase1.txt COPYONLY)

add_executable(TheGridSearch src/main.cpp)

set_property(TARGET TheGridSearch PROPERTY FOLDER "hackerrank/Algorithms/Implementation")