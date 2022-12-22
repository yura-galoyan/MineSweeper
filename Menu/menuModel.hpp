#pragma once
#include "../Library/Types/types.hpp"
#include "../Library/Colors/Colors.hpp"
#include <ncurses.h>
#include <vector>
#include <string>


using keyType = int;
using Coord = unsigned;

using Tab = Win;
using List = std::vector<Tab>;
using keyType = int;
using Coords = std::pair<unsigned,unsigned>;


class MENUMODEL
{
protected:
    Tab currTab;
    List menuList;
    Coord overAllX = 67;
    int height = 10,
        width = 10,
        minesCount = 10;
    unsigned delta = 6;
    
public:
    MENUMODEL();
    Tab initTab(const Coord ,const Coord,const char*);
    Tab getCurrTab();
    window getWin(const int &);
    ~MENUMODEL();
};


