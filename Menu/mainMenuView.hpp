#pragma once
#include "menuView.hpp"
#include "mainMenuModel.hpp"

class MAINMENUVIEW
    :public MENUVIEW
{
public:
    MAINMENUVIEW( );

    void drawGameNameHeader();
    void createMainMenu(const List&);
    

    ~MAINMENUVIEW();
};
