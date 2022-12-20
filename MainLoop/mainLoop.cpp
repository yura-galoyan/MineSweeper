#include "mainLoop.hpp"

MAINLOOP::MAINLOOP(){

}

void MAINLOOP::startGame(){
    while(isOnMainLoop){
    MENUCONTROLLER menuController;
    menuController.startMenu();
    if(menuController.quit){  
        endwin();
        break;
    }
    else if(menuController.play){
        GAMECONTROLLER gameController(menuController.getYX(),menuController.getMC());
        gameController.startGame();    }
}
};

MAINLOOP::~MAINLOOP(){

}
