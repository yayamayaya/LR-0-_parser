
file (GLOB HDR ./*.hpp)
file (GLOB SRC ./*.cpp)

add_library(parsing_print ${HDR} ${SRC})

target_include_directories(
    parsing_print
    PRIVATE
    ./../common/
    ./../tokenizator
    ./../parsing_table
)