#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "game.h"
#include "util.h"

void run(Game * game){
  while(1){
    game->update();
    game->draw();
    if(kbhit()){
      game->keyOn(getchar());
    } 
    usleep(33000);
  }
}

int main(){
  srand(time(NULL));
  printf("\033[2J");
  Game * game = new Game();
  run(game);
  return 0;
}
