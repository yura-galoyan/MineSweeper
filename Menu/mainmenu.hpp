
#include "menu.hpp"

#include <ncurses.h>
#include <string>

using coord = unsigned;
using word = std::string;
using window = WINDOW*;


class MAINMENU
    :MENU{

private:

    
    MENUTABS play,options,records,quit;
    List menuList;
public:
    MAINMENU();

    void createMainMenu();
    void setUpBoardSize();
    void initScreen();
    void drawGameNameHeader();
    void initMainMenuTabs();

    window getWin(int);

    window getStartW();
    window getOptionsW();
    window getRecordsW();
    window getQuitW();

    ~MAINMENU();

};
