
file (GLOB HDR ./*.hpp)
file (GLOB SRC ./*.cpp)

add_library(parsing_table ${HDR} ${SRC})

target_include_directories(
    parsing_table
    PRIVATE
    ./../common/
)