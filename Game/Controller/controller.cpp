#include "controller.hpp"
#include <ncurses.h>

CONTROLLER::CONTROLLER(Coords yx,unsigned m):game{yx,m},                                                
                                             gameActive(true)
{ 
    noecho();
    cursOFF(); 
}

void CONTROLLER::startGame(){
    game.initGameView();
    while(gameActive){
        input = getPressedKey();
        game.proccess(input);
        if(keyIsPressed(CURSOR::action::open) && !game.gameIsStarted()){
            game.start();    
        }
    }
}

int CONTROLLER::getPressedKey(){
    return getch();
}

bool CONTROLLER::keyIsPressed(const int& key){
    return input == key;
}

CONTROLLER::~CONTROLLER(){

}