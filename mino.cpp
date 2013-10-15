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
  if(key <= KEY_UP){
    move(key);
  }else if(key < KEY_NUM){
    if(key == KEY_ROLL_R) roll(DIR_R);
    if(key == KEY_ROLL_L) roll(DIR_L);
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

void Mino::roll(int direction){
  int next_shape[4][2];
  int next_x = _pos_x;
  int next_y = _pos_y;
  bool hit_r = false;
  bool hit_l = false;
  
  for(int k = 0; k < 4; k++){
    if(direction == DIR_L){
      next_shape[k][0] = - _shape[k][1];
      next_shape[k][1] =   _shape[k][0];
    }else{
      next_shape[k][0] =   _shape[k][1];
      next_shape[k][1] = - _shape[k][0];
    }
  }

  _field->removeShape(_pos_x, _pos_y, _shape);

  //回転して壁にぶつかるか判定
  for(int k = 0; k < 4; k++){
    int x = next_x + next_shape[k][0];
    int y = next_y + next_shape[k][1];
    if(_field->hitPos(x, y)){
      if(next_shape[k][0] < 0){
        hit_l = true;
      }
      if(next_shape[k][0] > 0){
        hit_r = true;
      }
    }
  }
  
  //両側がぶつかった場合
  if(hit_l && hit_r) return;

  //片側がぶつかった場合
  if(hit_l || hit_r){
    if(hit_r){
      while(hit_r){
        hit_r = false;
        next_x -= 2;
        for(int k = 0; k < 4; k++){
          int x = next_x + next_shape[k][0];
          int y = next_y + next_shape[k][1];
          if(_field->hitPos(x, y)){
            if(next_shape[k][0] < 0){
              return;//左がつかえているので
            }
            if(next_shape[k][0] > 0){
              hit_r = true;
            }
          }
        }
      }
    }
    if(hit_l){
      while(hit_l){
        hit_l = false;
        next_x += 2;
        for(int k = 0; k < 4; k++){
          int x = next_x + next_shape[k][0];
          int y = next_y + next_shape[k][1];
          if(_field->hitPos(x, y)){
            if(next_shape[k][0] < 0){
              hit_l = true;
            }
            if(next_shape[k][0] > 0){
              return;//右がつかえているので
            }
          }
        }
      }
    }
  }

  //回転成功
  _pos_x = next_x;
  _pos_y = next_y;
  
  for(int k = 0; k < 4; k++){
    for(int l = 0; l < 2; l++){
      _shape[k][l] = next_shape[k][l];
    }
  }
  _field->putShape(_pos_x, _pos_y, _shape);
  
}
