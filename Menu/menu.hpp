#pragma once
//#include <ncurses.h>
#include <string>
using coord = unsigned;
using word = std::string;



class MAINMENU
{
protected:
    unsigned delta = 8;
    coord overAllX; 
    struct MENUTABS {
    coord coordY;
    //TODO: wrap WINDOW*  into layer of abstraction
  //  WINDOW* win;
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
    void drawTab(); //FIXME: Make this function VIRTUAL, but not PURE
    void initMainMenuTabs();
    //TODO: wrap WINDOW*  into layer of abstraction

   // WINDOW* getStartW();
   // WINDOW* getOptionsW();
   // WINDOW* getRecordsW();
   // WINDOW* getQuitW();

    ~MAINMENU();

};
