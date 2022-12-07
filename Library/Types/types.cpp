#include <ncurses.h>
#
using window = WINDOW*;


template <typename T1,typename T2,typename T3>
    struct Triple{

        T1 win;
        T2 second;
        T3 name;
};

using triple = Triple<window,int,const char*>;