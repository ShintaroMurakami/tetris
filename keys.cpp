#include "keys.h"

Keys::Keys(){
  reset();
}

void Keys::setOn(int c){
  if(c == 67) _right = true;
  if(c == 68) _left = true;
  if(c == 66) _down = true;
  // if(c == 65) _up = true;
  if(c == 32) _roll_r = true;//space

  _key = c;
}

void Keys::reset(){
  _right = false;
  _left  = false;
  _down  = false;
  _roll_r = false;
  _roll_l = false;
  _key = 0;
}

int Keys::getKey(){
  return _key;
}
