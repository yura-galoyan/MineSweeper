#include "menu.hpp"





class OPTIONS
    :public MENU{

private:
    List menuList;

public:
    void drawOptionsHeader( int,int);
    OPTIONS();
    void changeValue(const int &,int);
    void initOptionsTabs();
    void createOptionMenu();

    void highlightCursor(Tab,int);
    void unHighlightCursor(Tab,int);

    bool isNotOnLimit(int);
    int getOptionValue(Tab);
    Tab getTab(const int&);
    Coords getYX();
    unsigned getMC();

    ~OPTIONS();
};
