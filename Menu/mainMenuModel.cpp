#include "mainMenuModel.hpp"

MAINMENUMODEL::MAINMENUMODEL()
{
   initScreen();
   initMainMenuTabs();
   currTab = menuList[0];

}

void MAINMENUMODEL::initMainMenuTabs(){
    
    menuList.push_back( initTab( 0,         10,                "Play") );
    menuList.push_back( initTab( 1,menuList[0].coordY + delta, "Options") );
    menuList.push_back( initTab( 2,menuList[1].coordY + delta, "Records") );
    menuList.push_back( initTab( 3,menuList[2].coordY + delta, "Quit") );
}

void MAINMENUMODEL::initScreen(){
    initscr();
    use_default_colors();
    noecho();
    curs_set(0);
    refresh();
};

Tab MAINMENUMODEL::getTab(const int &i){
   return menuList[i];
}

MAINMENUMODEL::~MAINMENUMODEL(){
   endwin();
}
