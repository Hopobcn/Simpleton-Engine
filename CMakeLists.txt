cmake_minimum_required(VERSION 3.8)
project(simpleton-engine)

if (EXISTS ${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
endif()

add_library(simpleton INTERFACE)
target_include_directories(simpleton INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(simpleton INTERFACE cxx_std_17)
target_link_libraries(simpleton INTERFACE CONAN_PKG::entt CONAN_PKG::sdl2 CONAN_PKG::sdl2_ttf CONAN_PKG::glm CONAN_PKG::glew CONAN_PKG::jsonformoderncpp)

add_subdirectory(Pack)