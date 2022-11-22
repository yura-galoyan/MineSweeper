#include "Menu/MenuController/menuController.hpp"
#include "Game/Controller/controller.hpp"


int main(){
    MENUCONTROLLER menuController;
    menuController.startMenu();
        if(menuController.quit){  
        endwin();
        
    }
   else if(menuController.play){
        CONTROLLER controller;
        controller.startGame();
    }


}