
file (GLOB HDR ./*.hpp)
file (GLOB SRC ./*.cpp)

add_library(tokenizator ${HDR} ${SRC})

target_include_directories(
    tokenizator
    PRIVATE
    ./../common/
)