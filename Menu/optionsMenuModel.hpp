#pragma once
#include "menuModel.hpp"

class OPTIONSMENUMODEL
    :public MENUMODEL
{
private:
    List menuList;
    int coefficient;

public:
    OPTIONSMENUMODEL(/* args */);
    
    void changeValue(const int &,int);
    void initOptionsTabs();
    int getOptionValue(Tab);
    Tab getTab(const int&);
    Coords getYX();
    unsigned getMC();

    ~OPTIONSMENUMODEL();
};
