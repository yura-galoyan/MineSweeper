
#include "Menu/menu.hpp"
#include "ncurses.h"
const auto& pause = getch;


int main(){
    MENU menu;
    menu.createMenu();




    pause();
}