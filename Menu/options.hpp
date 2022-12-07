#include "menu.hpp"





class OPTIONS
    :public MENU{
private:

    MENUTABS height,width,mines_count,back;

    List menuList;


    void drawOptionsHeader();

public:
    OPTIONS(List);

    void initOptionsTabs();
    void createOptionMenu();
    WINDOW* getHeightW();
    WINDOW* getWidthW();
    WINDOW* getMinesCountW();
    WINDOW* getBackW();

    ~ OPTIONS();
};
