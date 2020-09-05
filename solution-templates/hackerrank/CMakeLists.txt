#configure_file(tests/input.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/input.txt COPYONLY)

add_definitions(-DTEST)

add_executable(HackerRankTemplate src/main.cpp)

set_property(TARGET HackerRankTemplate PROPERTY FOLDER "solution-templates/hackerrank")