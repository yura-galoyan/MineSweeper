#include "gameloop.hpp"



GAMELOOP::GAMELOOP(bool gameProcessOn):gameProcessOn(gameProcessOn)
{

}

GAMELOOP::operator bool(){
    return gameProcessOn;
}

GAMELOOP::~GAMELOOP(){

}