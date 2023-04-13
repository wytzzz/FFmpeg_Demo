cmake_minimum_required(VERSION 3.19)
project(FFmpeg_Demo)
set(CMAKE_CXX_STANDARD 11)

set(SRC_DIRS src)
foreach (src_dir ${SRC_DIRS})
    aux_source_directory(${src_dir} src_dir_file)
    set(SRC_FILES ${SRC_FILES} ${src_dir_file})
endforeach (src_dir)
include_directories(inc)


#ffmpeg
set(FFMPEG_LIBS avcodec avdevice postproc avformat avutil swresample swscale avfilter)
if(APPLE)
    # Mac平台编译器标志
    include_directories(${CMAKE_SOURCE_DIR}/ffmpeg_dep/mac/include)
    link_directories(${CMAKE_SOURCE_DIR}/ffmpeg_dep/mac/lib)
elseif(WIN32)
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)  #windows 需要dll在exe相同目录
    include_directories(${CMAKE_SOURCE_DIR}/ffmpeg_dep/windows/include)
    link_directories(${CMAKE_SOURCE_DIR}/ffmpeg_dep/windows/lib)
endif()


#sdl

set(SDL2_LIBS SDL2)
if(APPLE)
    include_directories(/usr/local/Cellar/sdl2/2.0.16/include)
    link_directories(/usr/local/Cellar/sdl2/2.0.16/lib)
elseif(WIN32)
    include_directories(SDL_dep/include)
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)  #windows 需要dll在exe相同目录
    include_directories(${CMAKE_SOURCE_DIR}/SDL_dep/windows/include)
    link_directories(${CMAKE_SOURCE_DIR}/SDL_dep/windows/lib)
endif()

add_subdirectory(chapter10)
add_subdirectory(chapter11)
add_subdirectory(chapter12)
add_subdirectory(chapter13)
add_subdirectory(chapter14)
add_subdirectory(chapter15)
add_subdirectory(Tutorial/SDK_Demo)
add_subdirectory(tools)