#pragma once
#include <ncurses.h>

using window = WINDOW*;


template <typename T1,typename T2,typename T3>
    struct Win_{

        T1 win;
        T2 index;
        T3 name;
        T2 coordY = 0;
    };

template <typename T1,typename T2>
    struct pair{
        T1 value;
        T2 state;
        
    };


using Cell = pair<int,bool>;
using Win = Win_<window,int,const char*>;