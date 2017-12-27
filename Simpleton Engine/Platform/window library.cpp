//
//  window library.cpp
//  Simpleton Engine
//
//  Created by Indi Kernick on 3/4/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "window library.hpp"

#include "../Utils/bool enable.hpp"

Platform::WindowLibrary Platform::makeWindowLibrary(const Uint32 flags) {
  CHECK_SDL_ERROR(SDL_Init(flags));
  return Platform::WindowLibrary(true);
}

Platform::Window Platform::makeWindow(const Window::Desc &desc) {
  return Window(CHECK_SDL_NULL(SDL_CreateWindow(
    desc.title.c_str(),
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    desc.size.x, desc.size.y,
    SDL_WINDOW_SHOWN |
    Utils::boolEnable(desc.resizable, SDL_WINDOW_RESIZABLE) |
    Utils::boolEnable(desc.openGL, SDL_WINDOW_OPENGL)
  )));
}

Platform::Renderer Platform::makeRenderer(Window &window, const bool vsync) {
  return Renderer(CHECK_SDL_NULL(SDL_CreateRenderer(
    window.get(),
    -1,
    SDL_RENDERER_ACCELERATED |
    Utils::boolEnable(vsync, SDL_RENDERER_PRESENTVSYNC)
  )));
}
