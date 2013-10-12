#include "game.h"

Game::Game(){
  _keys = new Keys();
  _drawer = new Drawer(_keys);
}

void Game::update(){
  _drawer->update();
  _keys->reset();
}

void Game::draw(){
  _drawer->print();
}

void Game::keyOn(int c){
  _keys->setOn(c);
}
