#include "Menu/MenuController/menuController.hpp"
#include "Game/Controller/controller.hpp"
const auto& pause = getch;


int main(){
    MENUCONTROLLER menuController;
    menuController.startMenu();
    if(menuController.quit){  
    endwin();
    printw("\n            Game is Over, press key to end");
    return 0;
    }

    CONTROLLER controller;
    controller.startGame();


    pause();
}