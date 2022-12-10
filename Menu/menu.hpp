#pragma once
#include "../Library/Types/types.cpp"
#include "../Library/Colors/Colors.hpp"
#include <ncurses.h>
#include <vector>
#include <string>

using keyType = int;
using Coord = int;


const keyType UP   = 'w';
const keyType DOWN = 's';
const auto colorWhite = 7;
const auto colorEmpty = -1;

using Tab = Win;
using List = std::vector<Tab>;
using keyType = int;
using maxCoords = std::pair<unsigned,unsigned>;

class MENU
{
private:
   
protected:
    COLOR green = {colorWhite,colorEmpty};
      
protected:
    Tab currTab;
    List menuList;

protected:    
    unsigned delta = 6;
    Coord overAllX = 67;

protected: 
    int height = 10,
        width = 10,
        minesCount = 10;
public:
    MENU(); 
    void clearScreen();

    Tab initTab(const Coord ,const Coord,const char*);

    void drawTab(Tab);
    void drawTab(Tab tab,int value);
    void drawHighlightedTab(Tab tab,int value);
    void moveCursor( Tab&, const Tab& );

    void printCenteredText(window,const char*);
    
    void highlightCursor(Tab);
    void unHighlightCursor(Tab);
    void changeHighlightedTab(Tab tab,int value);

    void setCurrTab(const Tab&);
    Tab getCurrTab();
    window getWin(const int &);


   
    ~MENU();
};

