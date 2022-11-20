#include "Menu/MenuController/menuController.hpp"
#include "Game/Controller/controller.hpp"


int main(){
    MENUCONTROLLER menuController;
    menuController.startMenu();
    if(menuController.quit){  
    endwin();
    return 0;
    }

    CONTROLLER controller;
    controller.startGame();


   getch();
}