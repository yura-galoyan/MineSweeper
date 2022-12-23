#pragma once

#include "menuView.hpp"
#include "optionsMenuModel.hpp"




class OPTIONSMENUVIEW
    :public MENUVIEW
{
public:
    OPTIONSMENUVIEW();
   
    void drawOptionsHeader(const int,const int);
    void createOptionMenu(const List& menuList);
    void highlightCursor(Tab,const int);
    void unHighlightCursor(Tab,const int);

    ~OPTIONSMENUVIEW();
};
