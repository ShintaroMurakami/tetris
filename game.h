#pragma once
#include "draw.h"
#include "keys.h"
#include "field.h"
#include "mino.h"
#include <unistd.h>

class Game {
  Drawer * _drawer;
  Keys   * _keys;
  Field  * _field;
  Mino   * _mino;
  int _turn_counter;
  int _turn_length;
  int _delete_animation_counter;

public:
  Game();
  void run();
  void update();
  void updateAsDeleteAnimation();
  void draw();
  void keyOn(int c);
  void putMino();

};
