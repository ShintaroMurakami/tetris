#pragma once
#include "field.h"
#include "Keys.h"

class Mino {
  int _shape[4][2];
  int _pos_x;
  int _pos_y;
  bool _fixed;
  Keys  * _keys;
  Field * _field;

public:
  Mino(Keys * keys, Field * field);
  void refresh();
  void update();
  bool move(int key);
  void fix();
};
