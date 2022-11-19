#pragma once
#include "ncurses.h"


namespace NC{

void startNcurses(){
    initscr();
    use_default_colors();
    noecho();
    curs_set(0);
    refresh();
};

}