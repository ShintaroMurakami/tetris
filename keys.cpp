#include "keys.h"

Keys::Keys(){
  reset();
}

void Keys::setOn(int c){
  if(c == 67) _key[KEY_RIGHT ] = true;
  if(c == 68) _key[KEY_LEFT  ] = true;
  if(c == 66) _key[KEY_DOWN  ] = true;
  if(c == 65) _key[KEY_UP    ] = true;
  if(c == 32) _key[KEY_ROLL_R] = true;//space

  _c = c;
}

void Keys::reset(){
  for(int i = 0; i < KEY_NUM; i++){
    _key[i] = 0;
  }
  _c = 0;
}

bool Keys::getKey(int key){
  if(key >= KEY_NUM) return false;
  if(key < 0) return false;
  return _key[key];
}
