#pragma once
#include "draw.h"
#include <unistd.h>

class Game {
  Drawer * _drawer;

public:
  Game();
  void run();
  void update();
  void draw();

};
