#include "mino.h"
#define MINO_TYPE_NUM 1

int g_mino_shape[MINO_TYPE_NUM][4][2] = {
  {{ 1, 1}, {-1, 1}, {-1,-1}, { 1,-1}}//四角
};

Mino::Mino(Keys * keys, Field * field){
  _keys = keys;
  _field = field;
  _pos_x = GAME_WIDTH;
  _pos_y = GAME_HEIGHT; 
  int type = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 2; j++){
      _shape[i][j] = g_mino_shape[type][i][j];
    }
  }
  _field->putShape(_pos_x, _pos_y, _shape);
}

void Mino::update(){
  int key;
  for(key = 0; key < KEY_NUM; key++){
    if(_keys->getKey(key)){
      break;
    }
  }
  if(key != KEY_NUM){
    move(key);
  }
}

bool Mino::move(int key){
  _next_x = _pos_x;
  _next_y = _pos_y;
  switch (key){
  case KEY_UP:
    _next_y = _pos_y - 2;
    break;
  case KEY_DOWN:
    _next_y = _pos_y + 2;
    break;
  case KEY_LEFT:
    _next_x = _pos_x - 2;
    break;
  case KEY_RIGHT:
    _next_x = _pos_x + 2;
    break;
  default:
    break;
  }
  _field->removeShape(_pos_x, _pos_y, _shape);
  _field->putShape(_next_x, _next_y, _shape);

  _pos_x = _next_x;
  _pos_y = _next_y;
}
