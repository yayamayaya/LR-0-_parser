file(GLOB HDRS ./*.hpp)

add_library(common INTERFACE)

set_property(TARGET common PROPERTY 
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/
)