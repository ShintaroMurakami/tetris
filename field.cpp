#include "Field.h"
#include <stdio.h>

int xToJ(int x){
  return (x - 1) / 2;
}

int yToI(int y){
  return (y - 1) / 2;
}

Field::Field(){
  for(int i = 0; i < GAME_HEIGHT; i++){
    for(int j = 0; j < GAME_WIDTH; j++){
      if(i > j + 8) _map[i][j] = true;
      else _map[i][j] = false;
    }
  }
}

void Field::update(){

}

void Field::draw(){
  printf("\033[%d;%dH" , 0, 0); 

  for(int i = 0; i < GAME_HEIGHT; i++){
    printf("|");
    for (int j = 0; j < GAME_WIDTH; j++){
      if(_map[i][j]){
        printf(" *");
      }else{
        printf(" -");
      }
    }
    printf("|\n");
  }
}

bool inTheField(int i, int j){
  if((i < 0) || (i >= GAME_HEIGHT)) return false;
  if((j < 0) || (j >= GAME_WIDTH )) return false;
  return true;
}

void Field::putShape(int x, int y, int (*shape)[2]){
  for(int k = 0; k < 4; k++){
    int i = yToI(y+shape[k][1]);
    int j = xToJ(x+shape[k][0]);
    if(inTheField(i, j)) _map[i][j] = true;
  }
}

void Field::removeShape(int x, int y, int (*shape)[2]){
  for(int k = 0; k < 4; k++){
    int i = yToI(y+shape[k][1]);
    int j = xToJ(x+shape[k][0]);
    if(inTheField(i, j)) _map[i][j] = false;
  }
}

bool Field::hitPos(int x, int y){
  int i = yToI(y);
  int j = xToJ(x);
  if(i >= GAME_HEIGHT) return true;
  if((j < 0) || (j >= GAME_WIDTH )) return true;
  if(i < 0) return false;//上は空間
  return _map[i][j];
}

bool Field::hitShape(int x, int y, int (*shape)[2]){
  for(int k = 0; k < 4; k++){
    if(hitPos(x+shape[k][0], y+shape[k][1])) return true;
  }
  return false;
}

bool Field::deleteTest(){
  bool delete_flag = false;
  for(int i = 0; i < GAME_HEIGHT; i++){
    int j;
    for(j = 0; j < GAME_WIDTH; j++){
      if(!_map[i][j]) break;
    }
    if(j == GAME_WIDTH){
      _delete_lines[i] = true;
      delete_flag = true;
    }else _delete_lines[i] = false;
  }
  return delete_flag;
}

void Field::deleteLines(){
  int delete_counter = 0;
  for(int i = GAME_HEIGHT-1; i >= 0; i--){
    if(_delete_lines[i]){
      delete_counter++;
    }
    if(delete_counter >= 0){
      for(int j = 0; j < GAME_WIDTH; j++){
        _map[i][j] = i - delete_counter >= 0 ? _map[i-delete_counter][j] : false;
      }
    }
  }
}
