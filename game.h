#pragma once
#include "draw.h"
#include <unistd.h>

class Game {
  Drawer * _drawer;
  int _on_key;

public:
  Game();
  void run();
  void update();
  void draw();
  void keyOn(int c);

};
