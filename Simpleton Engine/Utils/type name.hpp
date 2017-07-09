//
//  type name.hpp
//  Game Engine
//
//  Created by Indi Kernick on 18/4/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef engine_utils_type_name_hpp
#define engine_utils_type_name_hpp

#include <experimental/string_view>

namespace Utils {
  template <typename T>
  constexpr std::experimental::string_view typeName() {
    //pretty function outputs
    //std::experimental::string_view typeNameView() [T = int]
    const char *data = __PRETTY_FUNCTION__;
    while (*data != '[') {
      data++;
    }
    //trimming "[T = "
    data += 5;
    
    //subtracting 1 from the actual size of the string trims ']'
    size_t size = std::numeric_limits<size_t>::max();
    {
      const char *c = data;
      while (*c) {
        size++;
        c++;
      }
    }
    
    return {data, size};
  }
}

#endif
