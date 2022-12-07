
#include "menu.hpp"

#include <ncurses.h>
#include <string>

using coord = unsigned;
using word = std::string;
using window = WINDOW*;


class MAINMENU
    :public MENU{

private:

    
    List menuList;
    
public:
    MAINMENU();

    void createMainMenu();
    void setUpBoardSize();
    void initScreen();
    void drawGameNameHeader();
    void initMainMenuTabs();

    Tab getTab(const int&);
    ~MAINMENU();

};
