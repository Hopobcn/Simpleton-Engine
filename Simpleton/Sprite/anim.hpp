//
//  anim.hpp
//  Simpleton Engine
//
//  Created by Indi Kernick on 10/6/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef engine_sprite_anim_hpp
#define engine_sprite_anim_hpp

#include "id.hpp"

namespace Sprite {
  class Anim {
    static constexpr ID MASK = ~ID{0} >> ID{1};
    static constexpr ID STOPPED = ~MASK;
  
  public:
    Anim();
    Anim(ID, ID, bool = true);
    Anim(ID, ID, ID = 1, bool = true);
    
    void incr();
    void incrRepeat();
    bool incrStop();
    
    void start();
    void stop();
    bool enabled() const;
    bool disabled() const;
    
    void delay(ID);
    void noDelay();
    void maxDelay();
    void speed(double);
    
    ID firstSprite() const;
    ID sprite() const;
    ID sprite(ID) const;
    template <typename T>
    ID sprite(T) const;
    
    ID frame() const;
    ID frameOrZero() const;
    float progress() const;
    bool firstFrame() const;
    bool lastFrame() const;
    
  private:
    ID sprite_;
    ID frames_;
    ID frame_;
    ID delay_;
  };
}

#include "anim.inl"

#endif
