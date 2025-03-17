
file(GLOB DIRECS ./*)

add_subdirectory(common)
add_subdirectory(parsing_print)
add_subdirectory(parsing_table)
add_subdirectory(tokenizator)

file (GLOB MAIN_SRC ./*.cpp)
file (GLOB MAIN_HDR ./*.hpp)

add_library(parser ${MAIN_SRC} ${MAIN_HDR})

target_include_directories(
	parser
	PUBLIC
	./parsing_table/
	./tokenizator/
	./parsing_print
)

target_link_libraries(
    parser
	parsing_table
	parsing_print
	tokenizator
	common
)
