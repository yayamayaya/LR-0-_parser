
file(GLOB DIRECS ./*)

foreach(item ${DIRECS})
	if(IS_DIRECTORY ${item})
		add_subdirectory(${item})
		include_directories(${item})
	endif()
endforeach()

file (GLOB MAIN_SRC ./*.cpp)
file (GLOB MAIN_HDR ./*.hpp)

add_library(parser ${MAIN_SRC} ${MAIN_HDR})

target_include_directories(
	parser
	PUBLIC
	./common/
	./parsing_table/
	./tokenizator/
)

target_link_libraries(
    parser
	parsing_table
	tokenizator
)