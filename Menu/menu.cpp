#include "menu.hpp"
#include "ncurses.h"

MAINMENU::MAINMENU(){
    startNcurses();
    overAllX = getmaxx(stdscr)/2 - 40;
    initMainMenuTabs();
}

void MAINMENU::startNcurses(){
    initscr();
    use_default_colors();
    noecho();
    curs_set(0);
    refresh();
};


void MAINMENU::clearScreen(){
    clear();
    refresh();
}

void MAINMENU::initTab(MENUTABS &tab, coord Y,const char * text){
    tab.coordY = Y;
    tab.name = text;
    tab.win = newwin(7,60,Y,overAllX);
}


void MAINMENU::initMainMenuTabs(){
    initTab(play,    getmaxy(stdscr)/5,       "Play"    );
    initTab(options, play.coordY + delta,     "Options" );
    initTab(records, options.coordY + delta,  "Records" );
    initTab(quit,    records.coordY + delta,  "Quit"    );

};

void MAINMENU::createMainMenu(){
   clearScreen();
   move(1,0);
   DRAW::drawGameName();
   DRAW::drawTab(play.win,play.name);
   DRAW::drawTab(options.win,options.name);
   DRAW::drawTab(records.win,records.name);
   DRAW::drawTab(quit.win,quit.name);
}

WINDOW* MAINMENU::getStartW(){
    return play.win;
}


WINDOW* MAINMENU::getOptionsW(){
    return options.win;
}

WINDOW* MAINMENU::getRecordsW(){
    return records.win;
}

WINDOW* MAINMENU::getQuitW(){
    return quit.win;
}

MAINMENU::~MAINMENU(){
    endwin();
}
