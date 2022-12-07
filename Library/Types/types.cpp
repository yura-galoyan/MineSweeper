#include <ncurses.h>
#
using window = WINDOW*;


template <typename T1,typename T2,typename T3>
    struct Win_{

        T1 win;
        T2 index;
        T3 name;
        T2 coordY = 0;
};

using Win = Win_<window,int,const char*>;