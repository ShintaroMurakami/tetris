#include "game.h"
#define DEFAULT_TURN_LENGTH 30

Game::Game(){
  _keys = new Keys();
  _field = new Field();
  _mino = new Mino(_keys, _field);
  _turn_counter = 0;
  _turn_length = DEFAULT_TURN_LENGTH;
}

void Game::update(){
  _mino->update();
  _keys->reset();
  if(_turn_counter >= _turn_length){
    _mino->move(KEY_DOWN);
    _turn_counter = 0;
  }
  _turn_counter++;
}

void Game::draw(){
  _field->draw();
}

void Game::keyOn(int c){
  _keys->setOn(c);
}
