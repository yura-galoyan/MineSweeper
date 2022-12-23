#include "optionsMenuView.hpp"


OPTIONSMENUVIEW::OPTIONSMENUVIEW(){

}

void OPTIONSMENUVIEW::createOptionMenu(const List& menuList){
    clearScreen();
    drawOptionsHeader(1,62);
    drawTab(menuList[0]);
    drawTab(menuList[1]);
    drawTab(menuList[2]);
    drawTab(menuList[3]);
}

void OPTIONSMENUVIEW::drawOptionsHeader(const int y ,const int x){
      mvprintw(y,x,    " _____       _    _                ");
      mvprintw(y + 1,x,"|     | ___ | |_ |_| ___  ___  ___ ");
      mvprintw(y + 2,x,"|  |  || . ||  _|| || . ||   ||_ -|");
      mvprintw(y + 3,x,"|_____||  _||_|  |_||___||_|_||___|");
      mvprintw(y + 4,x,"       |_|                         ");
}

void OPTIONSMENUVIEW::highlightCursor(Tab tab,const int value){
    green.startColor(tab.win);
    drawTab(tab,value);
    green.endColor(tab.win);
};
void OPTIONSMENUVIEW::unHighlightCursor(Tab tab,const int value){
    green.endColor(tab.win);
    drawTab(tab,value);
};


OPTIONSMENUVIEW::~ OPTIONSMENUVIEW(){

}
