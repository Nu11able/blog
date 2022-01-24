# cmake使用记录

## cmake使用模板
```cmake
#CMake的最低版本要求
cmake_minimum_required(VERSION 2.8)
 
#项目名称
PROJECT (project_name)
 
#设置版本是 Debug 还是 Release
SET(CMAKE_BUILD_TYPE "Debug")
 
#设置SRC_FILE的值,指示源代码文件夹
SET(SRC_FILE src/)
 
#设置包含目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)

#设置输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
 
#添加编译参数,比如add_definitions(-DDEBUG)将在gcc命令行添加DEBUG宏定义
add_definitions(-g)
 
#添加可执行文件
ADD_EXECUTABLE(main ${SRC_FILE}/main.cc)
```


## cmake预定义变量
`以下假设项目文件夹路径为/home/name/project`
|变量|值|
|-|-|
|PROJECT_SOURCE_DIR|/home/name/project|

