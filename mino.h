#pragma once
#include "field.h"
#include "Keys.h"

enum {DIR_R, DIR_L};

class Mino {
  int _shape[4][2];
  int _pos_x;
  int _pos_y;
  bool _fixed;
  bool _hit_bottom_flag;
  Keys  * _keys;
  Field * _field;

public:
  Mino(Keys * keys, Field * field);
  void refresh();
  void update();
  bool move(int key);
  void fix();
  bool hitBottomFlag();
  void roll(int direction);
};
