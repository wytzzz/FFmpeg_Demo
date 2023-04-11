##video_transformer

add_executable(my_ffplay ffplay.c cmdutils.c)
target_link_libraries(my_ffplay ${FFMPEG_LIBS} ${LINK_LIBS} ${SDL2_LIBS})
