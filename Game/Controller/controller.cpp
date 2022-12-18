#include "controller.hpp"
#include <ncurses.h>

CONTROLLER::CONTROLLER(Coords yx,unsigned m):game{yx,m},                                                
                                             gameIsActive{true}
{ 
    noecho();
}

void CONTROLLER::startGame(){
    game.initGameView();
    while(gameIsActive && !( game.isWin() ) && !( game.isOver() )){

        int input = getPressedKey();
        if(input == CURSOR::action::open && !game.isStarted()){
            game.start();    
        }
        else game.proccess(input);
    }

    clear();
    game.setGameState(false);
    gameIsActive = false;

    if(game.isOver()){
        game.printGameOverHeader(labelPosition);
    }
    else if(game.isWin()){
        game.printYouWinHeader(labelPosition);
    }

}


int CONTROLLER::getPressedKey(){
    return getch();
}

CONTROLLER::~CONTROLLER(){

}