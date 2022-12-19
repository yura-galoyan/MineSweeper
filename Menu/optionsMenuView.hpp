#pragma once

#include "menuView.hpp"
#include "optionsMenuModel.hpp"




class OPTIONSMENUVIEW
    :public MENUVIEW
{
private:
    OPTIONSMENUMODEL optMenuModel;

public:
    OPTIONSMENUVIEW();
   
    void drawOptionsHeader(const int,const int);
    void createOptionMenu();
    void highlightCursor(Tab,const int);
    void unHighlightCursor(Tab,const int);

    ~OPTIONSMENUVIEW();
};
