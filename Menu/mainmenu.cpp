#include "mainmenu.hpp"

MAINMENU::MAINMENU()
{
   initScreen();
   initMainMenuTabs();
   currTab = menuList[0];

}

void MAINMENU::initMainMenuTabs(){
    
    menuList.push_back( initTab( 0,         10,                "Play") );
    menuList.push_back( initTab( 1,menuList[0].coordY + delta, "Options") );
    menuList.push_back( initTab( 2,menuList[1].coordY + delta, "Records") );
    menuList.push_back( initTab( 3,menuList[2].coordY + delta, "Quit") );
}

void MAINMENU::initScreen(){
    initscr();
    use_default_colors();
    noecho();
    curs_set(0);
    refresh();
};

Tab MAINMENU::getTab(const int &i){
   return menuList[i];
}

void MAINMENU::createMainMenu(){
   clearScreen();
   drawGameNameHeader();
   drawTab(menuList[0]); 
   drawTab(menuList[1]);
   drawTab(menuList[2]);
   drawTab(menuList[3]);
}          

void MAINMENU::drawGameNameHeader(){
             mvprintw(1,62," _____  _            _____                                 \n");
             mvprintw(2,62,"|     ||_| ___  ___ |   __| _ _ _  ___  ___  ___  ___  ___ \n");
             mvprintw(3,62,"| | | || ||   || -_||__   || | | || -_|| -_|| . || -_||  _|\n");
             mvprintw(4,62,"|_|_|_||_||_|_||___||_____||_____||___||___||  _||___||_|  \n");
             mvprintw(5,62,"                                            |_|            \n");
}     

MAINMENU::~MAINMENU(){
   endwin();
}
