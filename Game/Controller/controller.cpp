#include "controller.hpp"
#include <ncurses.h>

CONTROLLER::CONTROLLER():board{{10,10}},gameloop(true),cursor{10,10}
{
   
}

void CONTROLLER::startGame(){

    board.createBoard();
    cursor.placeCursor();
    while(gameloop){
        auto key = getch();
        cursor.interact(getPressedKey());
    }
}

int CONTROLLER::getPressedKey(){
    return getch();
}

CONTROLLER::~CONTROLLER(){

}