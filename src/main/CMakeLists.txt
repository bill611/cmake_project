# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

add_executable(${EXE} ${DIR_LIB_SRCS})

# message(STATUS "message main ${ADD_LIBS}")
# 链接库
target_link_libraries (${EXE} ${ADD_LIBS})

