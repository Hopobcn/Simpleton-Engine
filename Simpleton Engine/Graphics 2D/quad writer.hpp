//
//  quad writer.hpp
//  Simpleton Engine
//
//  Created by Indi Kernick on 22/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef engine_graphics_2d_quad_writer_hpp
#define engine_graphics_2d_quad_writer_hpp

#include "depth.hpp"
#include "renderer.hpp"
#include "sheet tex.hpp"
#include "../Math/rect.hpp"

namespace G2D {
  enum class Origin {
    TOP_LEFT,
    TOP_MID,
    TOP_RIGHT,
    MID_RIGHT,
    BOTTOM_RIGHT,
    BOTTOM_MID,
    BOTTOM_LEFT,
    MID_LEFT,
    CENTER
  };

  class Section {
  public:
    Section(Section &&) = default;
    Section &operator=(Section &&) = default;
    Section(const RenderParams &, const Sprite::Sheet &);
  
    /// Get the RenderParams object associated with this section
    const RenderParams &params() const;
    /// Get the Sprite::Sheet object associated with this section
    const Sprite::Sheet &sheet() const;
    /// Remove all quads
    void clear();
    /// Make space for additional quads in the current section
    void reserveQuads(size_t);
    /// Sort the quads in the current section by the given sorting predicate
    template <typename Function>
    void sort(Function &&);
  
    /// Start a new quad and return it
    Quad &quad();
    /// Start a new quad the is a duplicate of the previous quad and return it
    Quad &dup();
    
    /// Set the depth of the current quad
    void depth(float);
    /// Set the depth of the current quad using an enum
    template <typename Enum>
    void depth(Enum);
    
    /// Copy the positions of the verticies from the previous quad into the
    /// current quad
    void dupPos();
    /// Copy the positions of the verticies and the depth from the previous
    /// quad into the current quad
    void dupPosDepth();
    /// Write positions of verticies on the current quad as an axis-aligned
    /// rectangle.
    void tilePos(glm::vec2, glm::vec2 = {1.0f, 1.0f});
    /// Write positions of verticies on the current quad as a rectangle rotated
    /// around it's center. The quad is position relative to it's bottom left
    /// corner like tilePos.
    void rotTilePos(float, glm::vec2, glm::vec2 = {1.0f, 1.0f});
    /// Write positions of verticies on the current quad as rectangle rotated
    /// around a given origin. The quad is positioned relative to the origin.
    /// This function isn't quite as fast as rotTilePos without an origin.
    template <Origin ORIGIN>
    void rotTilePos(float, glm::vec2, glm::vec2 = {1.0f, 1.0f});
    
    /// Copy the texture coordinates of the verticies on the previous quad onto
    /// the current quad
    void dupTex();
    /// Write texture coordinates of vertices on the current quad assuming that
    /// the texture is sampled as an axis-aligned rectangle
    template <PlusXY PLUS_XY = PlusXY::RIGHT_UP>
    void tileTex(glm::vec2, glm::vec2);
    /// Write texture coordinates of vertices on the current quad assuming that
    /// the texture is sampled as an axis-aligned rectangle
    template <PlusXY PLUS_XY = PlusXY::RIGHT_UP>
    void tileTex(Math::RectPP<float>);
    /// Write texture coordinates of vertices on the current quad assuming that
    /// the texture is sampled as an axis-aligned rectangle
    template <PlusXY PLUS_XY = PlusXY::RIGHT_UP>
    void tileTex(Sprite::ID);
    /// Write texture coordinates of vertices on the current quad assuming that
    /// the texture is sampled as an axis-aligned rectangle
    template <PlusXY PLUS_XY = PlusXY::RIGHT_UP>
    void tileTex(std::string_view);
    
    /// Copy the quads into GPU memory and issue a draw call
    void render(Renderer &) const;
    
  private:
    RenderParams renderParams;
    const Sprite::Sheet &spriteSheet;
    std::vector<Quad> quads;
  };

  class QuadWriter {
  public:
    QuadWriter();
    
    /// Remove all of the sections
    void clear();
    /// Clear quads but preseve sections
    void clearQuads();
    
    /// Create a new section with the given rendering params or get an
    /// existing section with the same params.
    Section &section(const glm::mat3 &, const SheetTex &, glm::vec4 = glm::vec4{1.0f});
    
    /// Render each of the section
    void render(Renderer &) const;
    
  private:
    std::vector<Section> sections;
  };
}

#include "quad writer.inl"

#endif
