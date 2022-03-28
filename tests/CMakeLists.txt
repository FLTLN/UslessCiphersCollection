file(GLOB TESTS_SOURCES "*.cpp")
file(GLOB TESTS_ROUTINE "routine/*.*")

include_directories("${CMAKE_SOURCE_DIR}/lib/include" "${CMAKE_SOURCE_DIR}/tests/routine")

add_executable(tests "${TESTS_SOURCES}" "${TESTS_ROUTINE}")
target_link_libraries(tests ciph)
