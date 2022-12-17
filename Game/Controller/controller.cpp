#include "controller.hpp"
#include <ncurses.h>

CONTROLLER::CONTROLLER(Coords yx,unsigned m):game{yx,m},                                                
                                             gameIsActive(true)
{ 
    noecho();
    cursOFF(); 
}

void CONTROLLER::startGame(){
    game.initGameView();
    while(gameIsActive && !( game.isWin() ) && !( game.isOver() )){
        if(keyIsPressed(CURSOR::action::open) && !game.gameIsStarted()){
            game.start();    
        }
        input = getPressedKey();
        game.proccess(input);
    }
    clear();
    if(game.isOver()){
        game.printGameOverHeader(15);
    }
    else if(game.isWin()){
        game.printYouWinHeader(15);
    }
    getch();
}



int CONTROLLER::getPressedKey(){
    return getch();
}

bool CONTROLLER::keyIsPressed(const int& key){
    return input == key;
}

CONTROLLER::~CONTROLLER(){

}