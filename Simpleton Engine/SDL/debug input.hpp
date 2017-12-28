//
//  debug input.hpp
//  Simpleton Engine
//
//  Created by Indi Kernick on 28/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef engine_sdl_debug_input_hpp
#define engine_sdl_debug_input_hpp

#include <cstdint>

extern "C" struct SDL_WindowEvent;
extern "C" union SDL_Event;

namespace SDL {
  void printWindowEvent(SDL_WindowEvent);
  void printEvent(SDL_Event);
  void printWindowFlags(uint32_t);
}

#endif
