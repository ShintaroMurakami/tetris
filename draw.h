#pragma once
#include "keys.h"
#include "Field.h"

class Drawer {
  int _counter;
  Keys * _keys;
  int _on_key;
  
public:
  Drawer(Keys * keys);
  void update();
  void print();
};
