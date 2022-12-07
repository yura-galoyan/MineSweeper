#include "mainmenu.hpp"

MAINMENU::MAINMENU():
{
    initScreen();
    overAllX = getmaxx(stdscr)/2 - 40;
    initMainMenuTabs();
}

void MAINMENU::initScreen(){
    initscr();
    use_default_colors();
    noecho();
    curs_set(0);
    refresh();
};





void MAINMENU::initMainMenuTabs(){
    //getScreenMaxXY(); 
    initTab(play,    getmaxy(stdscr)/5,       "Play"    );
    initTab(options, play.coordY + delta,     "Options" );
    initTab(records, options.coordY + delta,  "Records" );
    initTab(quit,    records.coordY + delta,  "Quit"    );

};

void MAINMENU::createMainMenu(){
   clearScreen();
   drawGameNameHeader();
   drawTab(play.win,play.name);
   drawTab(options.win,options.name);
   drawTab(records.win,records.name);
   drawTab(quit.win,quit.name);I
}          

void MAINMENU::drawGameNameHeader(){
             mvprintw(1,62," _____  _            _____                                 \n");
             mvprintw(2,62,"|     ||_| ___  ___ |   __| _ _ _  ___  ___  ___  ___  ___ \n");
             mvprintw(3,62,"| | | || ||   || -_||__   || | | || -_|| -_|| . || -_||  _|\n");
             mvprintw(4,62,"|_|_|_||_||_|_||___||_____||_____||___||___||  _||___||_|  \n");
             mvprintw(5,62,"                                            |_|            \n");
}     



window MAINMENU::getWin(int i){
   return menuList[i];
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
