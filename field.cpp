#include "Field.h"
#include <stdio.h>

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
