#include "menu.hpp"





class OPTIONS
    :public MENU{

private:

    List menuList;
    void drawOptionsHeader();

public:
    OPTIONS();

    void initOptionsTabs();
    void createOptionMenu();

    Tab getTab(const int&);

    ~ OPTIONS();
};
