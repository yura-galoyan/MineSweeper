#include "controller.hpp"


CONTROLLER::CONTROLLER():board{{25,40}},gameloop(true)
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