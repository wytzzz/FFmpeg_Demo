cmake_minimum_required(VERSION 3.19)
project(FFmpeg_Demo)
set(CMAKE_CXX_STANDARD 11)

set(SRC_DIRS src)
foreach (src_dir ${SRC_DIRS})
    aux_source_directory(${src_dir} src_dir_file)
    set(SRC_FILES ${SRC_FILES} ${src_dir_file})
endforeach (src_dir)
include_directories(inc)

#target


#if(APPLE)
#    # Mac平台编译器标志
#    include_directories(${CMAKE_SOURCE_DIR}/ffmpeg_dep/mac/include)
#    link_directories(${CMAKE_SOURCE_DIR}/ffmpeg_dep/mac/lib)
#elseif(WIN32)
#
#endif()
# Windows平台编译器标志
include_directories(${CMAKE_SOURCE_DIR}/ffmpeg_dep/windows/include)
link_directories(${CMAKE_SOURCE_DIR}/ffmpeg_dep/windows/lib)
add_executable(proj_name main.cpp)
target_link_libraries(
        proj_name
        avcodec
        avdevice
        avfilter
        avformat
        avutil
        postproc
        swresample
        swscale
)

#add_subdirectory(chapter10)
#add_subdirectory(chapter11)
#add_subdirectory(chapter12)
#add_subdirectory(chapter13)
#add_subdirectory(chapter14)
#add_subdirectory(chapter15)
#
#add_subdirectory(Tutorial/SDK_Demo)