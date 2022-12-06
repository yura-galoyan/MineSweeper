
#include "menu.hpp"

#include <ncurses.h>
#include <string>

using coord = unsigned;
using word = std::string;
using window = WINDOW*;


class MAINMENU
    :MENU{

private:

    unsigned delta = 8;
    coord overAllX; 
    MENUTABS play,options,records,quit;

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
