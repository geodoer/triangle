Triangle的代码来自于1.6版本（最新的稳定版本）。

## 修改记录

1. 添加cmake，方便其他工程使用（并将原始代码分了不同工程）
2. 给triangulateio添加了默认值，并添加对triangulateio的回收函数
3. 增加导出Obj格式的接口，方便查看结果（可用meshlab进行查看）
4. 根据使用需求，编写一些demo

## CMake引用示例

一、在你的工程中，可编写一个`triangle.cmake`文件

- 可放到`.\cmake\triangle.cmake`下统一管理，文件内容如下

```cmake
if(TARGET triangle)
    return() #如果已经存在，则退出
endif()

# 引入FetchContent相关函数
include(FetchContent)

# 通过FetchContent在网上下载源代码
FetchContent_Declare(
    triangle
    GIT_REPOSITORY https://gitee.com/geodoer/triangle.git
)

# 确保下载成功，并添加到cmake
FetchContent_MakeAvailable(triangle)
```

二、在你的工程中引用`triangle`

1. 在根`CMakeLists.txt`中引入`triangle`

```cmake
#只需将triangle.cmake文件加进来即可
include(cmake/triangle.cmake)
```

2. 链接到你需要使用的target中

```cmake
add_library(main SHARED ${all_files}) #你的target
target_link_libraries(main triangle)  #链接traingle即可
```