//
//  main.cpp
//  Pack
//
//  Created by Indi Kernick on 24/2/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "app.hpp"
#include <iostream>

int main(int argc, const char **argv) {
#ifdef RELEASE
  try {
    runApp(argc - 1, argv + 1);
  } catch (ArgError &e) {
    printUsage();
    return EXIT_SUCCESS;
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
#else
  runApp(argc - 1, argv + 1);
#endif
  
  return 0;
}
