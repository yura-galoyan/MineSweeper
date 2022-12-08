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

class MENU
{
private:
   
    bool isInMenu = true;
    COLOR green = {colorWhite,colorEmpty};
      
protected:
    Tab currTab;

protected:
  

protected:    
    unsigned delta = 8;
    Coord overAllX = 60;

protected: 
    void drawTab(window,const char*);
    List menuList;
public:
    MENU(); 
    void clearScreen();
    Tab initTab(const Coord ,const Coord,const char*);

    Tab getCurrTab();

    window getWin(const int &);
    void moveCursor( Tab&, const Tab& );
    void highlightCursor( Tab);
    void unHighlightCursor(Tab);
    void chooseSubMenu();
    void setCurrTab(const Tab&);
    ~MENU();
};

