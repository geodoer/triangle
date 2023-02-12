set(TARGET_NAME triangle)

add_library(${TARGET_NAME} STATIC triangle.cpp)
target_compile_definitions(${TARGET_NAME} PRIVATE -DTRILIBRARY -DANSI_DECLARATORS)
if(WIN32)
  target_compile_definitions(${TARGET_NAME} PRIVATE -DNO_TIMER)
endif()
target_include_directories(${TARGET_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})
