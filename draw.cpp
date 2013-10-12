#include <stdio.h>
#include "draw.h"
#include "util.h"
#define GAME_HEIGHT 16
#define GAME_WIDTH  8

Drawer::Drawer(){
 _counter = 0;
 printf("\033[2J"); //画面クリア
}

void Drawer::print(){
  printf("\033[%d;%dH" , 0, 0); 
  
  if(kbhit()){
    int c = getchar();
  for(int i = 0; i < GAME_HEIGHT; i++){
    printf("|");
    for (int j = 0; j < GAME_WIDTH; j++){
      printf(" %c", c);
    }
    printf("|\n");
  }
  }else{
  for(int i = 0; i < GAME_HEIGHT; i++){
    printf("|");
    for (int j = 0; j < GAME_WIDTH; j++){
      printf("%2d", _counter/30);
    }
    printf("|\n");
  }
  }
  _counter++;
}
