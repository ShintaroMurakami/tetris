#pragma once

enum {
  KEY_RIGHT,
  KEY_LEFT,
  KEY_DOWN,
  KEY_UP,
  KEY_ROLL_R,
  KEY_ROLL_L,
  KEY_NUM
};

class Keys {
  //bool _right;
  //bool _left;
  //bool _down;
  //bool _roll_r;
  //bool _roll_l;
  bool _key[KEY_NUM];
  int _c;
public:
  Keys();
  void setOn(int c);
  void reset();
  bool getKey(int key);
};
