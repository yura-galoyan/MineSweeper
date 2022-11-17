#include "menuController.hpp"





MENUCONTROLLER::MENUCONTROLLER():menuLoop{true},
                                                //s                    //w
                    menuCursor{{{ {menu.getOptionsW(),1},  {menu.getStartW(),0} },
                                { {menu.getRecordsW(),2},  {menu.getStartW(),0} },
                                { {menu.getQuitW(),3},     {menu.getOptionsW(),1} },
                                { {menu.getQuitW(),3},     {menu.getRecordsW(),2} } } }
{
    currTab.first = menu.getStartW();
    currTab.second = 0;
}

void MENUCONTROLLER::startMenu(){
    menu.createMenu();
    menuCursor.highlightCursor(currTab);
    while(menuLoop){
       actionKey = chooseAction();
       nextTab = menuCursor.getNextTab(currTab, actionKey); //TODO add move or press condition
       menuCursor.moveCursor(nextTab,actionKey);
    }
}

//TODO add function to analize action is for moving or for pressing

keyType MENUCONTROLLER::chooseAction(){
    keyType key = getPressedKey();
    switch(key){
        case 's': 
            return dir.down;
        case 'w':
            return dir.up;
            break;
    }
}

keyType MENUCONTROLLER::getPressedKey(){
    return getch();
}

MENUCONTROLLER::~MENUCONTROLLER(){
    
}
