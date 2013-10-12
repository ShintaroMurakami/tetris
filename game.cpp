#include "game.h"

Game::Game(){
  _drawer = new Drawer();
  _keys = new Keys();
}

void Game::update(){

  _keys->reset();
}

void Game::draw(){
  _drawer->print();
}

void Game::keyOn(int c){
  _keys->setOn(c);
}
