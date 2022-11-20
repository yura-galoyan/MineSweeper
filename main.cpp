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

printw("         _               __                                         "           );
printw("  /\\/\\  (_) _ __    ___ / _\\__      __ ___   ___  _ __    ___  _ __ "        );
printw(" /    \\ | || '_ \\  / _ \\ \\ \\ \\ /\\ / // _ \\ / _ \\| '_ \\  / _ \\| '__|" );
printw("/ /\\/\\ \\| || | | ||  __/_\\ \\ \\ V  V /|  __/|  __/| |_) ||  __/| |   "     );
printw("\\/    \\/|_||_| |_| \\___|\\__/  \\_/\\_/  \\___| \\___|| .__/  \\___||_|   "  );
printw("                                                 |_|                "           );

    pause();
}