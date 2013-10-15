#pragma once
#define GAME_HEIGHT 16
#define GAME_WIDTH  8

class Field {
  bool _map[GAME_HEIGHT][GAME_WIDTH];
 

public:
  Field();
  void update();
  void draw();
  void putShape(int x, int y, int (*shape)[2]);
  void removeShape(int x, int y, int (*shape)[2]);

};
