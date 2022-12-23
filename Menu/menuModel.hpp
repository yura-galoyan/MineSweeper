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
    Coord overAllX = 67;
    int height = 10,
        width = 10,
        minesCount = 10;
    unsigned delta = 6;
    Tab initTab(const Coord ,const Coord,const char*);
    
    List menuList;
    
public:
    MENUMODEL();
    Tab getCurrTab();
    List getMenuList();
    ~MENUMODEL();
};


