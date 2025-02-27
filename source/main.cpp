//

// main.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 03:03:53 2016 stephane galibert
// Last update Sun Jun  5 15:22:19 2016 stephane galibert
//

#include <string>
#include <iostream>
#include <stdexcept>
#include "Application.hpp"
#include "build_config.h"
#ifdef START_GTEST
  #include "gtest.h"
#endif

#ifdef START_GTEST
int main(int argc, char **argv)
#else
int main(void)
#endif
{
  bbman::Application appli;

  #ifdef START_GTEST

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

  #endif // ifdef LAUNCH_GTEST
  try {
    appli.init();
  } catch (std::runtime_error const& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return appli.play();
}
