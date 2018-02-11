//
//  types.hpp
//  Simpleton Engine
//
//  Created by Indi Kernick on 11/2/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef engine_graphics_2d_types_hpp
#define engine_graphics_2d_types_hpp

#include <array>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace G2D {
  using PosType = glm::vec3;
  using TexCoordType = glm::vec2;
  using ElemType = uint16_t;
  
  struct Vertex {
    PosType pos;
    TexCoordType texCoord;
  };
  
  using Quad = std::array<Vertex, 4>;
  using Quads = std::vector<Quad>;
  using QuadIter = typename Quads::iterator;
  using Elems = std::vector<ElemType>;
  
  using TextureID = size_t;
}

#endif