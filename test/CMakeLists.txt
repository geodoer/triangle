option(Build_Test "Build test" OFF)

if(NOT Build_Test)
  return()
endif()

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
add_executable(test ${SrcFiles})
target_link_libraries(test PRIVATE triangle)
target_link_libraries(test PRIVATE doctest_with_main)