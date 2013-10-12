#include "game.h"

Game::Game(){
  _drawer = new Drawer();
  _on_key = 0;
}

void Game::update(){

}

void Game::draw(){
  _drawer->print();
}

void Game::keyOn(int c){

}
