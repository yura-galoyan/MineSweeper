#pragma once
#include <ncurses.h>
#include <string>
using coord = unsigned;
using word = std::string;
using window = WINDOW*;


class MAINMENU
{
protected:
    unsigned delta = 8;
    coord overAllX; 
    struct MENUTABS {
    coord coordY;
    window win;
    const char * name;
} play,options,records,quit;

public:
    MAINMENU();
    void createMainMenu();
    void clearScreen();
    void setUpBoardSize();
    void initScreen();
    void initTab(MENUTABS&,coord,const char*);
    void drawGameNameHeader();
    void drawTab(window,const char*);
    void initMainMenuTabs();


   window getStartW();
   window getOptionsW();
   window getRecordsW();
   window getQuitW();

    ~MAINMENU();

};
