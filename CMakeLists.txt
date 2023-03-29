cmake_minimum_required(VERSION 3.19)
project(FFmpeg_Demo)

include_directories(inc)

set(SRC_DIRS src)
foreach (src_dir ${SRC_DIRS})
    aux_source_directory(${src_dir} src_dir_file)
    set(SRC_FILES ${SRC_FILES} ${src_dir_file})
endforeach (src_dir)


#语言
set(CMAKE_CXX_STANDARD 11)


#头文件
include_directories(ffmpeg_lib/include/)

#target
add_executable(demo main.cpp)

#动态链接
set(ffmpeg_libs_dir ${PROJECT_SOURCE_DIR}/ffmpeg_lib/lib)
link_directories(${ffmpeg_libs_dir})
file(GLOB FFMPEG_LIBS ${ffmpeg_libs_dir}/*.dylib)



add_subdirectory(chapter10)
add_subdirectory(chapter11)
add_subdirectory(chapter12)
add_subdirectory(chapter13)
add_subdirectory(chapter14)
add_subdirectory(chapter15)

add_subdirectory(Tutorial/SDK_Demo)