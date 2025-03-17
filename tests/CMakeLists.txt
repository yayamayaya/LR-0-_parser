
project(tests)


add_executable(tests tests.cpp)

target_link_libraries(tests parser)

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

target_include_directories(
    tests
    PRIVATE
    ./../src/
)
