#pragma once
#include "menuView.hpp"
#include "mainMenuModel.hpp"

class MAINMENUVIEW
    :public MENUVIEW
{
private:
    MAINMENUMODEL mainMenuModel;
public:
    MAINMENUVIEW( );



    void drawGameNameHeader();
    void createMainMenu();
    

    ~MAINMENUVIEW();
};
