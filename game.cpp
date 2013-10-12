#include "game.h"

Game::Game(){
  _drawer = new Drawer();
}

void Game::update(){

}

void Game::draw(){
  _drawer->print();


}

