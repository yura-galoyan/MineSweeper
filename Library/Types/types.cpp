#include "ncurses.h"

class triple{
public:
    WINDOW* first;
    int second;
    const char* third;
public:
    triple(WINDOW *f = stdscr,int s = 1,const char*t = "\0"){
        first = f;
        second = s;
        third = t;
    }




};