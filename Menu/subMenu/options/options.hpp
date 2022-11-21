#include "../../menu.hpp"


class OPTIONS:private MAINMENU
{
private:

    MENUTABS height,width,mines_count,back;

public:
    OPTIONS();
    void initOptionsTabs();
    void createOptionMenu();
    //TODO: wrap WINDOW*  into layer of abstraction
//    WINDOW* getHeightW();
//    WINDOW* getWidthW();
//    WINDOW* getMinesCountW();
//    WINDOW* getBackW();
     void drawOptionsHeader();
    ~ OPTIONS();
};
