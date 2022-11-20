#include "draw.hpp"


void DRAW::drawTab(WINDOW * win,const char* text){
    box(win,0,0);
    printCenteredText(win,text);
    wrefresh(win);
    refresh();
}

void DRAW::printCenteredText(WINDOW * win, const char *text){
    std::string ex = text;
    coord halfX = win->_maxx/2 - ex.length()/2;
    coord halfY = win->_maxy/2;
    mvwprintw(win,halfY,halfX,"%s",text);
}

void DRAW::drawGameName(){
move(1,0);
printw("     _____  _            _____                                 \n");
printw("    |     ||_| ___  ___ |   __| _ _ _  ___  ___  ___  ___  ___ \n");
printw("    | | | || ||   || -_||__   || | | || -_|| -_|| . || -_||  _|\n");
printw("    |_|_|_||_||_|_||___||_____||_____||___||___||  _||___||_|  \n");
printw("                                                |_|            \n");
}

void DRAW::drawOptions(){
printw("                                       \n");
printw("     _____       _    _                \n");
printw("    |     | ___ | |_ |_| ___  ___  ___ \n");
printw("    |  |  || . ||  _|| || . ||   ||_ -|\n");
printw("    |_____||  _||_|  |_||___||_|_||___|\n");
printw("           |_|                         \n");

}