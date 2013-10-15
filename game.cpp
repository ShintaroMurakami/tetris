#include "game.h"
#define DEFAULT_TURN_LENGTH 30
#define DELETE_ANIMETION_LENGTH (DEFAULT_TURN_LENGTH/2) 

Game::Game(){
  _keys = new Keys();
  _field = new Field();
  _mino = new Mino(_keys, _field);
  _turn_counter = 0;
  _delete_animation_counter = 0;
  _turn_length = DEFAULT_TURN_LENGTH;
}

void Game::update(){
  if(_delete_animation_counter > 0){
    updateAsDeleteAnimation();
    return;
  }
  _mino->update();
  _keys->reset();
  if(_turn_counter >= _turn_length){
    _mino->move(KEY_DOWN);
    _turn_counter = 0;
  }
  if(_mino->hitBottomFlag()){
    putMino();
  }
  _turn_counter++;
}

void Game::updateAsDeleteAnimation(){
  bool visible = _delete_animation_counter / (DELETE_ANIMETION_LENGTH / 4) % 2;
  _field->updateAsDeleteAnimation(visible);
  _delete_animation_counter--;
  if(_delete_animation_counter == 0){
    _field->deleteLines();
    _mino->refresh();
  }
}

void Game::putMino(){
  _mino->fix();
  if(_field->deleteTest()){
    _delete_animation_counter = DELETE_ANIMETION_LENGTH;
  }else{
    _mino->refresh();
  }
}

void Game::draw(){
  _field->draw();
}

void Game::keyOn(int c){
  _keys->setOn(c);
}

