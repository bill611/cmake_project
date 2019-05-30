# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})

#message(STATUS "drive ${CURRENT_FOLDER}")

# 将当前目录作为库文件名添加到全局变量ADD_LIBS中，需要加PARENT_SCOPE生效父接文件变量
set (ADD_LIBS ${CURRENT_FOLDER} ${ADD_LIBS} PARENT_SCOPE)
# message(STATUS "message mode2 ${ADD_LIBS}")

# 生成链接库
add_library (${CURRENT_FOLDER} ${DIR_LIB_SRCS})

