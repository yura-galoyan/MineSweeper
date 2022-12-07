
#include "menu.hpp"

#include <ncurses.h>
#include <string>

using coord = unsigned;
using word = std::string;
using window = WINDOW*;


class MAINMENU
    :public MENU{

private:

    
    MENUTABS play,options,records,quit;
    List menuList;
public:
    MAINMENU(List);

    void createMainMenu();
    void setUpBoardSize();
    void initScreen();
    void drawGameNameHeader();
    void initMainMenuTabs();


    window getStartW();
    window getOptionsW();
    window getRecordsW();
    window getQuitW();

    ~MAINMENU();

};
