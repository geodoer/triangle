option(BuildTriangle_Test "Build Triangle test" OFF)

if(NOT BuildTriangle_Test)
  return()
endif()

set(TARGET_NAME test)

include(FetchContent)
FetchContent_Declare(
    doctest
    GIT_REPOSITORY "https://github.com/doctest/doctest"
    GIT_TAG "v2.4.9"
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(doctest)

file(GLOB_RECURSE SrcFiles ${CMAKE_CURRENT_LIST_DIR}/*.cpp ${CMAKE_CURRENT_LIST_DIR}/*.h ${CMAKE_CURRENT_LIST_DIR}/*.hpp)

enable_testing()
add_executable(${TARGET_NAME} ${SrcFiles})
target_link_libraries(${TARGET_NAME} PRIVATE triangle)
target_link_libraries(${TARGET_NAME} PRIVATE doctest_with_main)