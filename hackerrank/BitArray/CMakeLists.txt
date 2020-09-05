configure_file(tests/input10.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/input10.txt COPYONLY)
configure_file(tests/testcase5.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase5.txt COPYONLY)
configure_file(tests/testcase6.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase6.txt COPYONLY)
configure_file(tests/testcase8.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase8.txt COPYONLY)

add_executable(BitArray src/main.cpp)

set_property(TARGET BitArray PROPERTY FOLDER "hackerrank/Cpp/OtherConcepts")