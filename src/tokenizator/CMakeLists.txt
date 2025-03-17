
file (GLOB HDR ./*.hpp)
file (GLOB SRC ./*.cpp)

add_library(tokenizator ${SRC})

target_link_libraries(tokenizator PRIVATE common)


target_include_directories(
    tokenizator
    PRIVATE
)
