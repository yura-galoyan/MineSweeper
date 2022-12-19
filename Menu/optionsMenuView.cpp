#include "optionsMenuView.hpp"


OPTIONSMENUVIEW::OPTIONSMENUVIEW(){

}

void OPTIONSMENUVIEW::createOptionMenu(){
    clearScreen();
    drawOptionsHeader(1,62);
    drawTab(optMenuModel.getTab(0) );
    drawTab(optMenuModel.getTab(1) );
    drawTab(optMenuModel.getTab(2) );
    drawTab(optMenuModel.getTab(3) );
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
