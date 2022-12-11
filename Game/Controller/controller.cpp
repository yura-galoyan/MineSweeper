#include "controller.hpp"
#include <ncurses.h>

CONTROLLER::CONTROLLER(Coords yx,unsigned m):game{yx,m},                                                
                                             gameActive(true)
{ 
    noecho();
    cursOFF(); 
}

void CONTROLLER::startGame(){
    game.startGame();
    while(gameActive){
        game.interact(getPressedKey());
    }
}



int CONTROLLER::getPressedKey(){
    return getch();
}

CONTROLLER::~CONTROLLER(){

}