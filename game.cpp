#include "game.h"

Game::Game(){
  _keys = new Keys();
  _field = new Field();
  _mino = new Mino(_keys, _field);
}

void Game::update(){
  _mino->update();
  _keys->reset();
}

void Game::draw(){
  _field->draw();
}

void Game::keyOn(int c){
  _keys->setOn(c);
}
