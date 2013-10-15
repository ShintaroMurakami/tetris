#pragma once
#include "field.h"
#include "Keys.h"

class Mino {
  int _shape[4][2];
  int _next_shape[4][2];
  int _pos_x;
  int _pos_y;
  int _next_x;
  int _next_y;
  Keys  * _keys;
  Field * _field;

public:
  Mino(Keys * keys, Field * field);
  void update();
  bool move(int key);
};
