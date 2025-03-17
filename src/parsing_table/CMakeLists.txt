
file (GLOB HDR ./*.hpp)
file (GLOB SRC ./*.cpp)

add_library(parsing_table ${HDR} ${SRC})

target_link_libraries(parsing_table common)