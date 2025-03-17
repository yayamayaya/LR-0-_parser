
file (GLOB HDR ./*.hpp)
file (GLOB SRC ./*.cpp)

add_definitions(-D YY_NO_UNPUT)

add_library(tokenizator ${SRC})

target_link_libraries(tokenizator PRIVATE common)
