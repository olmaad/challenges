configure_file(tests/mytestcase0.txt ${CMAKE_CURRENT_BINARY_DIR}/tests/mytestcase0.txt COPYONLY)

add_executable(FraudulentActivityNotifications src/main.cpp)