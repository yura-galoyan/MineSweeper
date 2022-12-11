#include "options.hpp"


OPTIONS::OPTIONS(){
   
    initOptionsTabs();
}



void OPTIONS::initOptionsTabs(){
   menuList.push_back( initTab(0,          10,              "Height") ) ;
   menuList.push_back( initTab(1,menuList[0].coordY + delta,"Width") ) ;
   menuList.push_back( initTab(2,menuList[1].coordY + delta,"Mines Count") ) ;
   menuList.push_back( initTab(3,menuList[2].coordY + delta,"Back") ) ;
}

void OPTIONS::createOptionMenu(){
    clearScreen();
    drawOptionsHeader(1,62);
    drawTab(menuList[0]);
    drawTab(menuList[1]);
    drawTab(menuList[2]);
    drawTab(menuList[3]);
}

void OPTIONS::changeValue(const int &value,int op){
                coof = (height * width * 3) / 4;
        switch(value){
            case 0:
                height = (height + op > 30) ? ( height) % 20 : (op < 0 && height + op < 10) ? height + 20 : height + op  ;
                break;
            case 1:
                width = (width + op > 60) ? ( width) % 50 : (op < 0 && width + op < 10) ? width + 50 : width + op  ;
                break;
            case 2:
                minesCount = minesCount + op > coof ? minesCount % ( coof - 10 ): (minesCount + op < 10) ? minesCount + coof - 10 : minesCount + op;
                break;
            default:
                break;
    }  
}


void OPTIONS::drawOptionsHeader(int y ,int x){
      mvprintw(y,x,    " _____       _    _                ");
      mvprintw(y + 1,x,"|     | ___ | |_ |_| ___  ___  ___ ");
      mvprintw(y + 2,x,"|  |  || . ||  _|| || . ||   ||_ -|");
      mvprintw(y + 3,x,"|_____||  _||_|  |_||___||_|_||___|");
      mvprintw(y + 4,x,"       |_|                         ");
}

void OPTIONS::highlightCursor(Tab tab,int value){
    green.startColor(tab.win);
    drawTab(tab,value);
    green.endColor(tab.win);
};
void OPTIONS::unHighlightCursor(Tab tab,int value){
    green.endColor(tab.win);
    drawTab(tab,value);
};


int OPTIONS::getOptionValue(Tab tab){
    switch(tab.index){
            case 0: 
                return height;
            case 1:
                return width;
            case 2:
                return minesCount;
            default:
                break;
    }
    return -1;
}

Tab OPTIONS::getTab(const int &i){
   return menuList[i];
}

Coords OPTIONS::getYX(){
    return {height,width};
}

unsigned OPTIONS::getMC(){
    return minesCount;
}


OPTIONS::~ OPTIONS(){

}
