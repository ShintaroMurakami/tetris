#include "mino.h"
#include <stdlib.h>
#define MINO_TYPE_NUM 7

int g_mino_shape[MINO_TYPE_NUM][4][2] = {
  {{-3,-1}, {-1,-1}, { 1,-1}, { 3,-1}},//長い
  {{ 1, 1}, {-1, 1}, {-1,-1}, { 1,-1}},
  {{-2, 0}, { 0, 0}, { 0,-2}, { 2,-2}},
  {{-2,-2}, { 0,-2}, { 0, 0}, { 2, 0}},
  {{-2,-2}, {-2, 0}, { 0, 0}, { 2, 0}},
  {{-2, 0}, { 0, 0}, { 2, 0}, { 2,-2}},
  {{-2, 0}, { 0, 0}, { 0,-2}, { 2, 0}}
};

int g_mino_default_pos[MINO_TYPE_NUM][2] = {
  {GAME_WIDTH/2*2  , -2},
  {GAME_WIDTH/2*2  , -2},
  {GAME_WIDTH/2*2+1, -1},
  {GAME_WIDTH/2*2+1, -1},
  {GAME_WIDTH/2*2+1, -1},
  {GAME_WIDTH/2*2+1, -1},
  {GAME_WIDTH/2*2+1, -1}
};

Mino::Mino(Keys * keys, Field * field){
  _keys = keys;
  _field = field;
  refresh();
}

void Mino::refresh(){
  int type = rand() % MINO_TYPE_NUM;
  _fixed = false;
  _hit_bottom_flag = false;
  _pos_x = g_mino_default_pos[type][0];
  _pos_y = g_mino_default_pos[type][1];
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 2; j++){
      _shape[i][j] = g_mino_shape[type][i][j];
    }
  }
  _field->putShape(_pos_x, _pos_y, _shape);
}

void Mino::update(){
  if(_fixed) return;
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

void Mino::fix(){
  _fixed = true;
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
    if(next_y > _pos_y) _hit_bottom_flag = true;
    return false;
  }
  
  _field->putShape(next_x, next_y, _shape);

  _pos_x = next_x;
  _pos_y = next_y;
  return true;
}

bool Mino::hitBottomFlag(){
  return _hit_bottom_flag;
}
