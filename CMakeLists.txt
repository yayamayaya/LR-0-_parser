cmake_minimum_required(VERSION 3.11)

project(parser)

execute_process(COMMAND flex -o src/tokenizator/tokenizator.cpp src/tokenizator/tokenizator.l)

#add_definitions(-DDEBUG)


add_definitions(
    -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Wpedantic -Werror
)

option(COMPILE_TESTS  "Test compiling"   ON)
option(COMPILE_DRIVER "Driver compiling" ON)

if (COMPILE_TESTS)
    find_package(GTest REQUIRED)

    include_directories(${GTEST_INCLUDE_DIRS})

    add_subdirectory(tests)
endif()

if (COMPILE_DRIVER)
    add_executable(driver driver.cpp)

    target_link_libraries(driver parser)

    target_include_directories(driver PRIVATE ./src)
endif()

add_subdirectory(src)

