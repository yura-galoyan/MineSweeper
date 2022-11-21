#include "menu.hpp"

MAINMENU::MAINMENU(){
    initScreen();
    //TODO: Wrap into layer of abstaction
    // overAllX = getmaxx(stdscr)/2 - 40;
    initMainMenuTabs();
}

void MAINMENU::initScreen(){
    // initscr();
    // use_default_colors();
    // noecho();
    // curs_set(0);
    // refresh();
};


void MAINMENU::clearScreen(){
    //TODO: Wrap into layer of abstaction
    //clear();
    //refresh();
}

void MAINMENU::initTab(MENUTABS &tab, coord Y,const char * text){
    tab.coordY = Y;
    tab.name = text;
    //TODO: Wrap into layer of abstaction
   // tab.win = newwin(7,60,Y,overAllX);
}


void MAINMENU::initMainMenuTabs(){
    //TODO: Wrap getScreenMaxXY(); layer of abstaction
    //initTab(play,    getmaxy(stdscr)/5,       "Play"    );
    initTab(options, play.coordY + delta,     "Options" );
    initTab(records, options.coordY + delta,  "Records" );
    initTab(quit,    records.coordY + delta,  "Quit"    );

};

void MAINMENU::createMainMenu(){
   clearScreen();
   drawGameNameHeader();
//             drawTab(play.win,play.name);
//             drawTab(options.win,options.name);
//             drawTab(records.win,records.name);
//             drawTab(quit.win,quit.name);
}           //DRAW HEADER FUNCION
//TODO: try to wrap functions into layer of abstaction
void MAINMENU::drawGameNameHeader(){
//              mvprintw(1,62," _____  _            _____                                 \n");
//              mvprintw(2,62,"|     ||_| ___  ___ |   __| _ _ _  ___  ___  ___  ___  ___ \n");
//              mvprintw(3,62,"| | | || ||   || -_||__   || | | || -_|| -_|| . || -_||  _|\n");
//              mvprintw(4,62,"|_|_|_||_||_|_||___||_____||_____||___||___||  _||___||_|  \n");
//              mvprintw(5,62,"                                            |_|            \n");
}           //DRAW FUNCTION
//TODO: Wrap all ncurses concepts into layer of ABSTRACTION
//          void MAINMENU::drawTab(WINDOW * win,const char* text){
//              box(win,0,0);
//              printCenteredText(win,text);
//              wrefresh(win);
//              refresh();
//}

            //GET FUNCTIONS
//TODO: Wrap all ncurses concepts into layer of ABSTRACTION
//WINDOW* MAINMENU::getStartW(){
//    return play.win;
//}


//TODO: Wrap all ncurses concepts into layer of ABSTRACTION
//WINDOW* MAINMENU::getOptionsW(){
//    return options.win;
//}

//TODO: Wrap all ncurses concepts into layer of ABSTRACTION
//WINDOW* MAINMENU::getRecordsW(){
//    return records.win;
//}

//TODO: Wrap all ncurses concepts into layer of ABSTRACTION
//WINDOW* MAINMENU::getQuitW(){
//    return quit.win;
//}

MAINMENU::~MAINMENU(){
//    endwin();
//TODO: Wrap all ncurses concepts into layer of ABSTRACTION
}
