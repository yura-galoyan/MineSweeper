#include "controller.hpp"
#include <ncurses.h>

CONTROLLER::CONTROLLER(maxCoords yx,unsigned m):board{{yx.first,yx.second},m},
                                                gameActive(true),
                                                game{yx.first,yx.second,m},
                                                cursor{yx.first,yx.second}
{
   
}

void CONTROLLER::startGame(){

    board.createBoard();
    cursor.placeCursor();
    while(gameActive){
        cursor.interact(getPressedKey());
    }
}

int CONTROLLER::getPressedKey(){
    return getch();
}

CONTROLLER::~CONTROLLER(){

}