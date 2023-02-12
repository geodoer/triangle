option(BuildTriangle_TriCall "Build tricall" OFF)

if(NOT BuildTriangle_TriCall)
    return()
endif()

add_executable(tricall tricall.cpp)
target_link_libraries(tricall PRIVATE triangle)