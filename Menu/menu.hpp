#pragma once
#include "../Library/Types/types.cpp"
#include "../Library/Colors/Colors.hpp"

#include <vector>
#include <string>

using keyType = int;
using Coord = int;


const keyType UP   = 'w';
const keyType DOWN = 's';
const auto colorWhite = 7;
const auto colorEmpty = -1;

using Tab = triple;;
using List = std::vector<Tab>;
using keyType = int;

class MENU
{
private:
   
    bool isInMenu = true;
    COLOR green = {colorWhite,colorEmpty};  
    Tab currTab,nextTab;

protected:
    struct MENUTABS{
    Coord coordY;
    window win;
    const char * name;
    };

protected:    
    unsigned delta = 8;
    Coord overAllX;

protected: 
    void drawTab(window,const char*);

public:
    MENU(); 
    void clearScreen();
    void initTab(MENUTABS&,Coord,const char*);

    Tab getCurrTab();

    void moveCursor( Tab&, const Tab& );
    void highlightCursor(const Tab&);
    void unHighlightCursor(Tab&);
    void chooseSubMenu();
    ~MENU();
};

