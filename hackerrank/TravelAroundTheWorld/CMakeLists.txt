configure_file(tests/mytestcase0.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/mytestcase0.txt COPYONLY)
configure_file(tests/testcase0.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase0.txt COPYONLY)
configure_file(tests/testcase1.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase1.txt COPYONLY)
configure_file(tests/testcase3.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase3.txt COPYONLY)
configure_file(tests/testcase6.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase6.txt COPYONLY)

add_executable(TravelAroundTheWorld src/main.cpp)

set_property(TARGET TravelAroundTheWorld PROPERTY FOLDER "hackerrank/Algorithms/DynamicProgramming")