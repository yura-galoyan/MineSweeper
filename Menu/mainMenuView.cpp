#include "mainMenuView.hpp"


MAINMENUVIEW::MAINMENUVIEW(/* args */)
{
    
}



void MAINMENUVIEW::drawGameNameHeader(){
             mvprintw(1,62," _____  _            _____                                 \n");
             mvprintw(2,62,"|     ||_| ___  ___ |   __| _ _ _  ___  ___  ___  ___  ___ \n");
             mvprintw(3,62,"| | | || ||   || -_||__   || | | || -_|| -_|| . || -_||  _|\n");
             mvprintw(4,62,"|_|_|_||_||_|_||___||_____||_____||___||___||  _||___||_|  \n");
             mvprintw(5,62,"                                            |_|            \n");
}

void MAINMENUVIEW::createMainMenu(){
   clearScreen();
   drawGameNameHeader();
   drawTab(mainMenuModel.getTab(0)); 
   drawTab(mainMenuModel.getTab(1));
   drawTab(mainMenuModel.getTab(2));
   drawTab(mainMenuModel.getTab(3));
}   

MAINMENUVIEW::~MAINMENUVIEW()
{

}
