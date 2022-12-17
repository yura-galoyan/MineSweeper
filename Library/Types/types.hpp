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
    struct triple{
        T1 value;
        T2 isOpened;
        T2 isNotMarked;;
        
    };


using Cell = triple<int,bool>;
using Win = Win_<window,int,const char*>;