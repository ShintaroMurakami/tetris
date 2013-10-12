#include "game.h"

Game::Game(){
  _keys = new Keys();
  _drawer = new Drawer(_keys);
  _field = new Field();
}

void Game::update(){
  _drawer->update();
  _keys->reset();
}

void Game::draw(){
  _field->draw();

}

void Game::keyOn(int c){
  _keys->setOn(c);
}
