#include "options.hpp"







OPTIONS:: OPTIONS(/* args */){
   
    overAllX = getmaxx(stdscr)/2 - 40;
    initOptionsTabs();
}



void OPTIONS::initOptionsTabs(){
    initTab(height,getmaxy(stdscr)/5,"Height");
    initTab(width,height.coordY + delta,"Width");
    initTab(mines_count,width.coordY + delta,"Mines Count");
    initTab(back,mines_count.coordY + delta,"Back");
}

void OPTIONS::createOptionMenu(){
    clearScreen();
    move(1,0);
    DRAW::drawOptions();
    DRAW::drawTab(height.win,height.name);
    DRAW::drawTab(width.win,width.name);
    DRAW::drawTab(mines_count.win,mines_count.name);
    DRAW::drawTab(back.win,back.name);
}



WINDOW* OPTIONS::getHeightW(){
    return height.win;
};

WINDOW* OPTIONS::getWidthW(){
    return width.win;
}

WINDOW* OPTIONS::getMinesCountW(){
    return mines_count.win;
};

WINDOW* OPTIONS::getBackW(){
    return back.win;
};


OPTIONS::~ OPTIONS(){

}
