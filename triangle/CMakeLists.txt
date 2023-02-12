add_library(triangle STATIC triangle.cpp)
target_compile_definitions(triangle PRIVATE -DTRILIBRARY -DANSI_DECLARATORS)
if(WIN32)
  target_compile_definitions(triangle PRIVATE -DNO_TIMER)
endif()
# Generate position independent code
set_target_properties(triangle PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(triangle INTERFACE ${CMAKE_CURRENT_LIST_DIR})