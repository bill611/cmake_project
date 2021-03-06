# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目名称
project (cmake_project_mode)

# 项目版本
set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)
configure_file (
    "${PROJECT_SOURCE_DIR}/include/cmake_config.h.in"
    "${PROJECT_SOURCE_DIR}/include/cmake_config.h"
    )


# 添加编译过程变量
#set(CMAKE_VERBOSE_MAKEFILE ON)

# 设置交叉编译环境 ------------
set(CMAKE_SYSTEM_NAME Linux)
# to modify
# set(TOOLCHAIN_DIR $ENV{ANYKA_CROOS_PATH})
# set(TOOLCHAIN  ${TOOLCHAIN_DIR}/bin/arm-none-linux-gnueabi-)

set(CMAKE_C_COMPILER   	${TOOLCHAIN}gcc)
set(CMAKE_AR   			${TOOLCHAIN}ar)
set(CMAKE_LINKER   		${TOOLCHAIN}ld)
set(CMAKE_NM   			${TOOLCHAIN}nm)
set(CMAKE_OBJDUMP   	${TOOLCHAIN}objdump)
set(CMAKE_RANLIB   		${TOOLCHAIN}ranlib)
set(CMAKE_STRIP   		${TOOLCHAIN}strip)

# to modify
set(CMAKE_C_FLAGS "-D_GNU_SOURCE ${CMAKE_C_FLAGS}")

set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -DWATCHDOG_DEBUG -O0")
set(CMAKE_C_FLAGS_RELEASE "")
# 设置交叉编译环境 ------------

#设置执行文件存放路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

#设置库文件存放路径
#set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libs)

#功能函数获取当前目录及子目录(递归获取),添加到头文件搜索路径
function(func_include_sub_directories_recursively root_dir)
    if (IS_DIRECTORY ${root_dir})               # 当前路径如果是一个目录,则加入到包含目录
        #message("include dir: " ${root_dir})
        include_directories(${root_dir})
    endif()

    file(GLOB ALL_SUB RELATIVE ${root_dir} ${root_dir}/*) # 获得当前目录下的所有文件，加如ALL_SUB列表中

    foreach(sub ${ALL_SUB})
        if (IS_DIRECTORY ${root_dir}/${sub})
            func_include_sub_directories_recursively(${root_dir}/${sub}) # 对子目录递归调用，包含
        endif()
    endforeach()
endfunction()


# 项目的所有目录都为头文件搜索路径
#func_include_sub_directories_recursively(${PROJECT_SOURCE_DIR}/src)
#func_include_sub_directories_recursively(${PROJECT_SOURCE_DIR}/include)

# 增加其他目录头文件路径
include_directories(
	${PROJECT_SOURCE_DIR}/include
	)

# 添加库文件搜索路径
link_directories(
	${PROJECT_SOURCE_DIR}/libs
	)

# 添加库文件名称
link_libraries (
	pthread
	)

# 添加宏定义
# include(define.cmake)

# 增加打印信息
# message(STATUS "message test ${PROJECT_SOURCE_DIR}")

# 指定应用名称
set(EXE v)

set (ADD_LIBS "${ADD_LIBS}") 
# 增加子目录
add_subdirectory(src)

