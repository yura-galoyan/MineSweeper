#include "../../../Library/libraries.hpp"
#include "../../menu.hpp"


class OPTIONS:private MAINMENU
{
private:

    MENUTABS height,width,mines_count,back;

public:
    OPTIONS();
    void initOptionsTabs();
    void createOptionMenu();
    WINDOW* getHeightW();
    WINDOW* getWidthW();
    WINDOW* getMinesCountW();
    WINDOW* getBackW();
    ~ OPTIONS();
};
