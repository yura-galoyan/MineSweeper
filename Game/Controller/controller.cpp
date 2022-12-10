#include "controller.hpp"
#include <ncurses.h>

CONTROLLER::CONTROLLER(maxCoords yx,unsigned m):board{{yx.first,yx.second},m},gameloop(true),cursor{yx.first,yx.second}
{
   
}

void CONTROLLER::startGame(){

    board.createBoard();
    cursor.placeCursor();
    while(gameloop){
        cursor.interact(getPressedKey());
    }
}

int CONTROLLER::getPressedKey(){
    return getch();
}

CONTROLLER::~CONTROLLER(){

}