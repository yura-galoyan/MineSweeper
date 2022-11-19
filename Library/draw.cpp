#include "draw.hpp"


void DRAW::drawTab(WINDOW * win,const char* text){
    box(win,0,0);
    printCenteredText(win,text);
    wrefresh(win);
    refresh();
}

void DRAW::printCenteredText(WINDOW * win, const char *text){
    coord halfX = win->_maxx/2 - 3;
    coord halfY = win->_maxy/2;
    mvwprintw(win,halfY,halfX,"%5s",text);
}