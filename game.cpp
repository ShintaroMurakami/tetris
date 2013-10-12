#include "game.h"

Game::Game(){
  _keys = new Keys();
  _field = new Field();
}

void Game::update(){
  _keys->reset();
}

void Game::draw(){
  _field->draw();
}

void Game::keyOn(int c){
  _keys->setOn(c);
}
