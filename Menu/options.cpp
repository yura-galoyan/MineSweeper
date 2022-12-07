#include "options.hpp"


OPTIONS::OPTIONS(List){
   
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
    drawOptionsHeader();
    drawTab(height.win,height.name);
    drawTab(width.win,width.name);
    drawTab(mines_count.win,mines_count.name);
    drawTab(back.win,back.name);
}

void OPTIONS::drawOptionsHeader(){
      mvprintw(1,62," _____       _    _                ");
      mvprintw(2,62,"|     | ___ | |_ |_| ___  ___  ___ ");
      mvprintw(3,62,"|  |  || . ||  _|| || . ||   ||_ -|");
      mvprintw(4,62,"|_____||  _||_|  |_||___||_|_||___|");
      mvprintw(5,62,"       |_|                         ");
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
