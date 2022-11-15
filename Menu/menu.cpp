#include "menu.hpp"


MENU::MENU(){
    startNcurses();
    
    tab.start = getmaxy(stdscr)/4; 
    tab.options = tab.start + delta; 
    tab.records = tab.options + delta; 
    tab.quit = tab.records + delta;
    initializeTabs();
}

void MENU::startNcurses(){
    initscr();
    noecho();
    curs_set(0);
    refresh();
};

void MENU::initializeTabs(){
    start = newwin(7,60,tab.start,overAllX);
    options = newwin(7,60,tab.options,overAllX);
    records = newwin(7,60,tab.records,overAllX);
    quit = newwin(7,60,tab.quit,overAllX);
};

void MENU::createMenu(){
    drawStart();
    drawOptions();
    drawRecords();
    drawQuit();
}

void MENU::printCenteredText(WINDOW * win, const char *text){
    coord halfX = win->_maxx/2 - 3;
    coord halfY = win->_maxy/2;
    mvwprintw(win,halfY,halfX,"%6s",text);
}

void MENU::drawStart(){
    box(start,0,0);
    printCenteredText(start,"start");
    wrefresh(start);
};

void MENU::drawOptions(){
    box(options,0,0);
    printCenteredText(options,"options");
    wrefresh(options);
};

void MENU::drawRecords(){
    box(records,0,0);
    printCenteredText(records,"records");
    wrefresh(records);
};

void MENU::drawQuit(){
    box(quit,0,0);
    printCenteredText(quit,"quit");
    wrefresh(quit);
};

void MENU::setUpBoardSize(){

}

MENU::~MENU(){
    endwin();
}
