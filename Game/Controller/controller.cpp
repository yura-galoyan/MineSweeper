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
    
    mvprintw(2,20,"you are here");

    while(gameActive){
    if(!game.gameIsStarted()) mvprintw(3,20,"false");
    else mvprintw(3,20,"true");
        input = getPressedKey();
        game.proccess(input);
        if(keyIsPressed(CURSOR::action::open) && !game.gameIsStarted()){
            game.generateMap();
            
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