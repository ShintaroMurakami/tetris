#include "keys.h"

Keys::Keys(){
  reset();
}

void Keys::setOn(int c){
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
