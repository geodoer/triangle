#使用x11库编写了GUI
# 要求linux环境，并且安装x11：apt-get install libxss-dev libxxf86vm-dev libxkbfile-dev libxv-dev
if(NOT UNIX)
  return()
endif()

option(Build_ShowMe "Build showme" OFF)

if(Build_ShowMe)
  find_package(X11)
  add_executable(showme showme.c)
  target_link_libraries(showme PRIVATE triangle)
endif()