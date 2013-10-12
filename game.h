#pragma once
#include "draw.h"
#include "keys.h"
#include <unistd.h>

class Game {
  Drawer * _drawer;
  Keys   * _keys;

public:
  Game();
  void run();
  void update();
  void draw();
  void keyOn(int c);

};
