cmake_minimum_required (VERSION 3.2)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(Challenges)

include_directories("include")

add_subdirectory("include")
add_subdirectory(hackerrank)
add_subdirectory(ideone)
add_subdirectory(solution-templates)