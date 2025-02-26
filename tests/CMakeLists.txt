
project(tests)

file (GLOB HDR ./include/*.hpp)
file (GLOB SRC ./*.cpp)

add_executable(tests ${HDR} ${SRC})

target_link_libraries(
    tests
    parser
)

target_include_directories(
    tests
    PRIVATE
    ./include/
)
