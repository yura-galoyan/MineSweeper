#include "Menu/MenuController/menuController.hpp"
#include "Game/Controller/controller.hpp"

//FIXME: try changin everything in code independent from Ncurses, as much as possible
//TODO: FIND A WAY TO GET RID OF WINDOW*, MAKE ANOTHER CLASS THAT ALSO WORKS LIKE POINTER WITH unique_pointer PROBABLY
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