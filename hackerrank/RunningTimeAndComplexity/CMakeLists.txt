configure_file(tests/testcase0.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase0.txt COPYONLY)
configure_file(tests/testcase5.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/testcase5.txt COPYONLY)

add_executable(RunningTimeAndComplexity src/main.cpp)

set_property(TARGET RunningTimeAndComplexity PROPERTY FOLDER "HackerRank/Tutorials/30DaysOfCode")