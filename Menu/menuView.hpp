#pragma once
#include "../Library/Types/types.hpp"
#include "../Library/Colors/Colors.hpp"
#include <ncurses.h>
#include <vector>
#include <string>

using keyType = int;
using Coord = unsigned;

const keyType UP   = 'w';
const keyType DOWN = 's';
const auto colorWhite = 7;
const auto colorEmpty = -1;

using Tab = Win;
using List = std::vector<Tab>;
using keyType = int;
using Coords = std::pair<unsigned,unsigned>;

class MENUVIEW
{
protected:
    COLOR green = {2,colorWhite};
    unsigned delta = 6;
    Coord overAllX = 67;

protected: 
    int height = 10,
        width = 10,
        minesCount = 10;
public:
    MENUVIEW(); 
    void clearScreen();


    void drawTab(Tab);
    void drawTab(Tab tab,int value);
    void drawHighlightedTab(Tab tab,int value);
    void moveCursor( Tab&, const Tab& );
    void printCenteredText(window,const char*);
    
    void highlightCursor(Tab);
    void unHighlightCursor(Tab);




   
    ~MENUVIEW();
};

