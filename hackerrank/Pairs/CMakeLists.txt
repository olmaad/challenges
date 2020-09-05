configure_file(tests/testcase0.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase0.txt COPYONLY)

add_executable(Pairs src/main.cpp)

set_property(TARGET Pairs PROPERTY FOLDER "hackerrank/Algorithms/Search")