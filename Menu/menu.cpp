#include "menu.hpp"


MENU::MENU(){
    startNcurses();
    overAllX = getmaxx(stdscr)/2 - 40;
    initTabs();
}

void MENU::startNcurses(){
    initscr();
    noecho();
    curs_set(0);
    refresh();
};

void MENU::initTabs(){
    initStart();
    initOptions();
    initRecords();
    initQuit();

};

void MENU::initStart(){
    start.coordY = getmaxy(stdscr)/4;
    start.win = newwin(7,60,start.coordY,overAllX);
    start.name = "Start";
};

void MENU::initOptions(){    
    options.coordY = start.coordY + delta;
    options.win = newwin(7,60,options.coordY,overAllX);
    options.name = "Options";
};

void MENU::initRecords(){    
    records.coordY = options.coordY + delta;
    records.win = newwin(7,60,records.coordY,overAllX);
    records.name = "Records";
};

void MENU::initQuit(){
    quit.coordY = records.coordY + delta;
    quit.win = newwin(7,60,quit.coordY,overAllX);
    quit.name = "Quit";
};

void MENU::createMenu(){
   drawTab(start.win,start.name);
   drawTab(options.win,options.name);
   drawTab(records.win,records.name);
   drawTab(quit.win,quit.name);
}

void MENU::drawTab(WINDOW * win,const char* text){
    box(win,0,0);
    printCenteredText(win,text);
    wrefresh(win);
}

void MENU::printCenteredText(WINDOW * win, const char *text){
    coord halfX = win->_maxx/2 - 3;
    coord halfY = win->_maxy/2;
    mvwprintw(win,halfY,halfX,"%6s",text);
}

void MENU::setUpBoardSize(){

}

MENU::~MENU(){
    endwin();
}
