#include "menuController.hpp"


MENUCONTROLLER::MENUCONTROLLER():menuLoop{true},
                    mainMenuCursor{{{ {menu.getOptionsW(),1,"Options"},  {menu.getStartW(),0,"Play"}      },
                                    { {menu.getRecordsW(),2,"Records"},  {menu.getStartW(),0,"Play"}      },
                                    { {menu.getQuitW(),3,"Quit"},        {menu.getOptionsW(),1,"Options"} },
                                    { {menu.getQuitW(),3,"Quit"},        {menu.getRecordsW(),2,"Records"} } } },

                    optionsCursor{ {{ {optionsMenu.getWidthW(),1,"Width"},           {optionsMenu.getHeightW(),0,"Height"}      },
                                    { {optionsMenu.getMinesCountW(),2,"Mines Count"},{optionsMenu.getHeightW(),0,"Height"}      },
                                    { {optionsMenu.getBackW(),3,"Back"},             {optionsMenu.getWidthW(),1,"Width"}        }, 
                                    { {optionsMenu.getBackW(),3,"Back"},             {optionsMenu.getMinesCountW(),2,"Mines Count"}   }  } }
{
    
}

void MENUCONTROLLER::startMenu(){
    menu.createMainMenu();
    mainMenuCursor.highlightCursor(mainMenuCursor.getCurrTab());
    while(menuLoop){
       actionKey = chooseAction();
       Tab currTab = mainMenuCursor.getCurrTab();
       if(actionKey == action.down || actionKey == action.up){
        mainMenuCursor.moveCursor(currTab,actionKey);
       }
       else if(actionKey == action.enter ){
        if(currTab.second == 1){
            Tab currTab = optionsCursor.getCurrTab();
            optionsMenu.createOptionMenu();
            optionsCursor.highlightCursor(currTab);
            while(menuLoop){
            currTab = optionsCursor.getCurrTab();
            actionKey = chooseAction();
            if(actionKey == action.down || actionKey == action.up){
                optionsCursor.moveCursor(currTab,actionKey);
            }
            else if(actionKey == action.enter ){
             if(currTab.second == 3){
                menu.createMainMenu();
                mainMenuCursor.highlightCursor(mainMenuCursor.getCurrTab());
                break;
             }
            }
           }
        }
        else if(currTab.second == 0) {
            play = true;
            quit = false;
            menu.clearScreen();
            return;
            } 
      }
    }

}

//TODO add function to analize action is for moving or for pressing

keyType MENUCONTROLLER::chooseAction(){
    keyType key = getPressedKey();
    switch (key)
    {
    case 's':
        return action.down;
    case 'w':
        return action.up;
    case 'd':
        return action.enter;
    default:
        return 0;
    }
}

keyType MENUCONTROLLER::getPressedKey(){
    return getch();
}

MENUCONTROLLER::~MENUCONTROLLER(){

}
