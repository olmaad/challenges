configure_file(tests/testcase0.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase0.txt COPYONLY)

add_executable(CppVariadics src/main.cpp)