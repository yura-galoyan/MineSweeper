#pragma once
#include "../Library/libraries.hpp"

using coord = unsigned;
using word = std::string;




class MAINMENU
{
protected:
    unsigned delta = 8;
    coord overAllX; 
    struct MENUTABS {
    coord coordY;
    WINDOW* win;
    const char * name;
} play,options,records,quit;

public:
    MAINMENU();
    void createMainMenu();
    void clearScreen();
    void setUpBoardSize();
    void startNcurses();
    void initTab(MENUTABS&,coord,const char*);

    void initMainMenuTabs();

    WINDOW* getStartW();
    WINDOW* getOptionsW();
    WINDOW* getRecordsW();
    WINDOW* getQuitW();

    ~MAINMENU();

};
