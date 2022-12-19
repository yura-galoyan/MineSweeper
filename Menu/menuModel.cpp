#include "menuModel.hpp"

MENUMODEL::MENUMODEL(){

}

Tab MENUMODEL::initTab(const Coord i ,const Coord Y,const char * text){
    Tab tab;
    tab.coordY = Y;
    tab.name = text;
    tab.index = i;
    tab.win = newwin(5,45,Y,overAllX);
    return tab;
}

Tab MENUMODEL::getCurrTab(){
    return currTab;
}

window MENUMODEL::getWin(const int &i){
   return this->menuList[i].win;
}


MENUMODEL::~MENUMODEL(){

}