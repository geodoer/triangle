option(BuildTriangle_TriCall "Build tricall" OFF)

if(NOT BuildTriangle_TriCall)
endif()

add_executable(triangle_tricall tricall.cpp)
target_link_libraries(triangle_tricall PRIVATE triangle::triangle)
add_executable(triangle::tricall ALIAS triangle_tricall)