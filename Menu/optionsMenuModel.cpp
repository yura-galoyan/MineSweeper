#include "optionsMenuModel.hpp"


OPTIONSMENUMODEL::OPTIONSMENUMODEL(/* args */)
{
    initOptionsTabs();
}

void OPTIONSMENUMODEL::changeValue(const int &value,int op){
                coof = (height * width * 3) / 4;
        switch(value){
            case 0:
                height = (height + op > 30) ? ( height) % 20 : (op < 0 && height + op < 10) ? height + 20 : height + op  ;
                break;
            case 1:
                width = (width + op > 60) ? ( width) % 50 : (op < 0 && width + op < 10) ? width + 50 : width + op  ;
                break;
            case 2:
                minesCount = minesCount + op > coof ? minesCount % ( coof - 10 ): (minesCount + op < 10) ? minesCount + coof - 10 : minesCount + op;
                break;
            default:
                break;
    }  
}

int OPTIONSMENUMODEL::getOptionValue(Tab tab){
    switch(tab.index){
            case 0: 
                return height;
            case 1:
                return width;
            case 2:
                return minesCount;
            default:
                break;
    }
    return -1;
}

void OPTIONSMENUMODEL::initOptionsTabs(){
   menuList.push_back( initTab(0,          10,              "Height") ) ;
   menuList.push_back( initTab(1,menuList[0].coordY + delta,"Width") ) ;
   menuList.push_back( initTab(2,menuList[1].coordY + delta,"Mines Count") ) ;
   menuList.push_back( initTab(3,menuList[2].coordY + delta,"Back") ) ;
}


Tab OPTIONSMENUMODEL::getTab(const int &i){
   return menuList[i];
}

Coords OPTIONSMENUMODEL::getYX(){
    return {height,width};
}

unsigned OPTIONSMENUMODEL::getMC(){
    return minesCount;
}


OPTIONSMENUMODEL::~OPTIONSMENUMODEL()
{
}
