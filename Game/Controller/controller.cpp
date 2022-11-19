#include "controller.hpp"


CONTROLLER::CONTROLLER():board{{40,80}},gameloop(true)
{
   
}

void CONTROLLER::startGame(){
    board.createBoard();
    cursor.createCursor();
    while(gameloop){

    }
}



CONTROLLER::~CONTROLLER(){

}