#include <stdio.h>
#include "draw.h"
#define GAME_HEIGHT 16
#define GAME_WIDTH  8

Drawer::Drawer(Keys * keys){
 _counter = 0;
 _keys = keys;
 printf("\033[2J"); //画面クリア
}

void Drawer::update(){
  _on_key = _keys->getKey();
}

void Drawer::print(){
  printf("\033[%d;%dH" , 0, 0); 

  int c;
  if(_on_key){
    c = _on_key;
  }else{
    c = _counter/30;
  }
  
  for(int i = 0; i < GAME_HEIGHT; i++){
    printf("|");
    for (int j = 0; j < GAME_WIDTH; j++){
      printf("%3d", c);
    }
    printf("|\n");
  }
  _counter++;
}
