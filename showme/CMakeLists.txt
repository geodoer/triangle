#使用x11库编写了GUI
# 要求linux环境，并且安装x11：apt-get install libxss-dev libxxf86vm-dev libxkbfile-dev libxv-dev
if(NOT UNIX)
  return()
endif()

option(BuildTriangle_ShowMe "Build Triangle showme" OFF)

if(NOT BuildTriangle_ShowMe)
  return()
endif()

set(TARGET_NAME triangle_showme)
set(TARGET_ALIAS_NAME triangle::showme)

find_package(X11)
add_executable(${TARGET_NAME} showme.c)
target_link_libraries(${TARGET_NAME} PRIVATE triangle::triangle)

add_executable(${TARGET_ALIAS_NAME} ALIAS ${TARGET_NAME})