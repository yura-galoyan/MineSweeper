#include "game_controller.hpp"
#include <ncurses.h>

GAMECONTROLLER::GAMECONTROLLER(Coords yx,unsigned m):game{yx,m},gameIsActive{true}
{ 
    noecho();
}

void GAMECONTROLLER::startGame(){
    game.initView();
    while(gameIsActive && !( game.isWin() ) && !( game.isLost() )){
        int input = getPressedKey();
        if(input == CURSOR::action::OPEN && !game.isStarted()){
            game.start(); 
        }
        else game.proccess(input);
    }

    game.setGameState(false);
    gameIsActive = false;

    game.endGame();
    game.waitUntillInput();

}


int GAMECONTROLLER::getPressedKey(){
    return getch();
}

GAMECONTROLLER::~GAMECONTROLLER(){

}