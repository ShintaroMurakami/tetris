#include "mino.h"
#define MINO_TYPE_NUM 1;

int g_mino_shape[MINO_TYPE_NUM][4][2]{
  {{ 1, 1}, {-1, 1}, {-1,-1}, { 1,-1}}//四角
};

Mino::Mino(Keys * keys, Field * field){
  _keys = keys;
  _field = field;
  int type = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 2; j++){
      _shape[i][j] = g_mino_shape[type][i][j];
    }
  }

}

Mino::update(){

}
