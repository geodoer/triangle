option(Build_TriCall "Build tricall" OFF)

if(Build_TriCall)
  add_executable(tricall tricall.cpp)
  target_link_libraries(tricall PRIVATE triangle)
endif()