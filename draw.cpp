#include <stdio.h>
#include "draw.h"

Drawer::Drawer(Keys * keys){
 _counter = 0;
 _keys = keys;
 printf("\033[2J"); //画面クリア
}

void Drawer::update(){
  _on_key = _keys->getKey();
}

void Drawer::print(){
}
