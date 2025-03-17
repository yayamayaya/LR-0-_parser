
file (GLOB HDR ./*.hpp)
file (GLOB SRC ./*.cpp)

add_library(parsing_print ${HDR} ${SRC})

target_link_libraries(parsing_print PRIVATE common)

target_include_directories(
    parsing_print
    PRIVATE
    ./../tokenizator
    ./../parsing_table
)