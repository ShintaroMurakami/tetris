#pragma once

class Keys {
  bool _right;
  bool _left;
  bool _down;
  bool _roll_r;
  bool _roll_l;
  int _key;
public:
  Key();
  void setOn(int c);
  void reset();
}
