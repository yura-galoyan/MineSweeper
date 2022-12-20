#include "game_controller.hpp"
#include <ncurses.h>

GAMECONTROLLER::GAMECONTROLLER(Coords yx,unsigned m):game{yx,m},gameIsActive{true}
{ 
    noecho();
}

void GAMECONTROLLER::startGame(){
    game.initGameView();
    while(gameIsActive && !( game.isWin() ) && !( game.isLost() )){
        int input = getPressedKey();
        if(input == CURSOR::action::open && !game.isStarted()){
            game.start(); 
        }
        else game.proccess(input);
    }

    game.setGameState(false);
    gameIsActive = false;

    if(game.isLost()){
       game.revealAllBombs(); 
    }
    else if(game.isWin()){
        game.endGame();
    }
    game.waitUntillInput();

}


int GAMECONTROLLER::getPressedKey(){
    return getch();
}

GAMECONTROLLER::~GAMECONTROLLER(){

}