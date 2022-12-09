#include "menu.hpp"





class OPTIONS
    :public MENU{

private:
    int width = 10,
        height = 10,
        minesCount = 10;

    List menuList;
public:
    void drawOptionsHeader( int,int);
    OPTIONS();

    void initOptionsTabs();
    void createOptionMenu();

    Tab getTab(const int&);

    ~ OPTIONS();
};
