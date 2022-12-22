#include "mainLoop.hpp"

MAINLOOP::MAINLOOP(){

}

void MAINLOOP::start(){
    MENUCONTROLLER menuController;
    while(isOnMainLoop){
    menuController.startMenu();
    if(menuController.quitIsPressed){  
      exit();
    }
    else if(menuController.playIsPressed){
        GAMECONTROLLER gameController(menuController.getYX(),menuController.getMC());
        gameController.startGame();
    }
}
};

void MAINLOOP::exit(){
    isOnMainLoop = false;
    clear();
    endwin();
}
MAINLOOP::~MAINLOOP(){

}
