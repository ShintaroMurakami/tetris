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
      _map[i][j] = false;
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

bool inTheFeeld(int i, int j){
  if((i < 0) || (i >= GAME_HEIGHT)) return false;
  if((j < 0) || (j >= GAME_WIDTH )) return false;
  return true;
}

void Field::putShape(int x, int y, int (*shape)[2]){
  for(int k = 0; k < 4; k++){
    int i = yToI(y+shape[k][1]);
    int j = xToJ(x+shape[k][0]);
    if(inTheFeeld(i, j)) _map[i][j] = true;
  }
}

void Field::removeShape(int x, int y, int (*shape)[2]){
  for(int k = 0; k < 4; k++){
    int i = yToI(y+shape[k][1]);
    int j = xToJ(x+shape[k][0]);
    if(inTheFeeld(i, j)) _map[i][j] = false;
  }
}
