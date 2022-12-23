#pragma once

#include "menuModel.hpp"

#include <ncurses.h>
#include <string>

using coord = unsigned;
using word = std::string;
using window = WINDOW*;


class MAINMENUMODEL
    :public MENUMODEL{
    
public:
    MAINMENUMODEL();

    void initScreen();
    void initMainMenuTabs();
    Tab getTab(const int&);

    ~MAINMENUMODEL();

};
