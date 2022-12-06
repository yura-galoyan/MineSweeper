#include "Presenter.hpp"


Presenter::Presenter():menuLoop{true},
                    mainMenu{{{       {mainMenu.getOptionsW(),1,"Options"},  {menu.getStartW(),0,"Play"}      },
                                    { {mainMenu.getRecordsW(),2,"Records"},  {menu.getStartW(),0,"Play"}      },
                                    { {mainMenu.getQuitW(),3,"Quit"},        {menu.getOptionsW(),1,"Options"} },
                                    { {mainMenu.getQuitW(),3,"Quit"},        {menu.getRecordsW(),2,"Records"} } } },

                    options{ {{       {optionsMenu.getWidthW(),1,"Width"},           {optionsMenu.getHeightW(),0,"Height"}      },
                                    { {optionsMenu.getMinesCountW(),2,"Mines Count"},{optionsMenu.getHeightW(),0,"Height"}      },
                                    { {optionsMenu.getBackW(),3,"Back"},             {optionsMenu.getWidthW(),1,"Width"}        }, 
                                    { {optionsMenu.getBackW(),3,"Back"},             {optionsMenu.getMinesCountW(),2,"Mines Count"}   }  } }
{
    
}

void Presenter::startMenu(){
    mainMenu.createMainMenu();
    mainMenu.highlightCursor(mainMenu.getCurrTab());
    while(menuLoop){
       actionKey = chooseAction();
       Tab currTab = mainMenu.getCurrTab();
       if(actionKey == action.down || actionKey == action.up){
        mainMenu.moveCursor(currTab,actionKey);
       }
       else if(actionKey == action.enter ){
        if(currTab.second == 1){
            Tab currTab = options.getCurrTab();
            optionsMenu.createOptionMenu();
            options.highlightCursor(currTab);
            while(menuLoop){
            currTab = options.getCurrTab();
            actionKey = chooseAction();
            if(actionKey == action.down || actionKey == action.up){
                options.moveCursor(currTab,actionKey);
            }
            else if(actionKey == action.enter ){
             if(currTab.second == 3){
                mainMenu.createMainMenu();
                mainMenu.highlightCursor(mainMenu.getCurrTab());
                break;
             }
            }
           }
        }
        else if(currTab.second == 0) {
            play = true;
            quit = false;
            mainMenu.clearScreen();
            return;
            }
        else if(currTab.second == 3) {
            play = false;
            quit = true;
            return;
        } 
      }
    }

}


keyType Presenter::chooseAction(){
    keyType key = getPressedKey();
    switch (key)
    {
    case 's':
        return action.down;
    case 'w':
        return action.up;
    case 'e':
        return action.enter;
    default:
        return 0;
    }
}

keyType Presenter::getPressedKey(){
    return getch();
}

Presenter::~Presenter(){

}
