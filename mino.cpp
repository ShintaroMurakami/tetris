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
  int next_x = _pos_x;
  int next_y = _pos_y;
  switch (key){
    case KEY_UP:
      next_y = _pos_y - 2;
      break;
    case KEY_DOWN:
      next_y = _pos_y + 2;
      break;
    case KEY_LEFT:
      next_x = _pos_x - 2;
      break;
    case KEY_RIGHT:
      next_x = _pos_x + 2;
      break;
    default:
      break;
  }

  _field->removeShape(_pos_x, _pos_y, _shape);

  if(_field->hitShape(next_x, next_y, _shape)){
    _field->putShape(_pos_x, _pos_y, _shape);
    return false;
  }
  
  _field->putShape(next_x, next_y, _shape);

  _pos_x = next_x;
  _pos_y = next_y;
  return true;
}
