#include "options.hpp"


OPTIONS::OPTIONS(){
   
    initOptionsTabs();
}



void OPTIONS::initOptionsTabs(){
   menuList.push_back( initTab(0,          10,              "Height = 10") ) ;
   menuList.push_back( initTab(1,menuList[0].coordY + delta,"Width  = 10") ) ;
   menuList.push_back( initTab(2,menuList[1].coordY + delta,"Mines Count = 10") ) ;
   menuList.push_back( initTab(3,menuList[2].coordY + delta,"Back") ) ;
}

void OPTIONS::createOptionMenu(){
    clearScreen();
    drawOptionsHeader(1,62);
    drawTab(menuList[0].win,menuList[0].name);
    drawTab(menuList[1].win,menuList[1].name);
    drawTab(menuList[2].win,menuList[2].name);
    drawTab(menuList[3].win,menuList[3].name);
}

void OPTIONS::drawOptionsHeader(int y ,int x){
      mvprintw(y,x,    " _____       _    _                ");
      mvprintw(y + 1,x,"|     | ___ | |_ |_| ___  ___  ___ ");
      mvprintw(y + 2,x,"|  |  || . ||  _|| || . ||   ||_ -|");
      mvprintw(y + 3,x,"|_____||  _||_|  |_||___||_|_||___|");
      mvprintw(y + 4,x,"       |_|                         ");
}

Tab OPTIONS::getTab(const int &i){
   return menuList[i];
}


OPTIONS::~ OPTIONS(){

}
