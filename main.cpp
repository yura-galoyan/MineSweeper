
#include "Menu/menu.hpp"
#include "ncurses.h"
#include "Menu/MenuControl/menuController.hpp"
const auto& pause = getch;


int main(){
    MENUCONTROLLER menuController;
    menuController.startMenu();



    pause();
}