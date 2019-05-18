cmake_minimum_required(VERSION 3.8)
project(pack)

add_executable(pack
    "search dir.cpp"
    "search dir.hpp"
    "sort by frame.cpp"
    "sort by frame.hpp"
    "load images.cpp"
    "load images.hpp"
    "stb_rect_pack.c"
    "stb_rect_pack.h"
    "rects from images.cpp"
    "rects from images.hpp"
    "pack rects.cpp"
    "pack rects.hpp"
    "blit images.cpp"
    "blit images.hpp"
    "write atlas.cpp"
    "write atlas.hpp"
    "write image.cpp"
    "write image.hpp"
    "app.cpp"
    "app.hpp"
    "main.cpp"
)

target_compile_features(pack PRIVATE cxx_std_17)
target_compile_definitions(pack PRIVATE -DRELEASE)
target_include_directories(pack PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pack PRIVATE simpleton CONAN_PKG::libpng)

install(TARGETS pack
        RUNTIME DESTINATION bin
)