#include "Presenter.hpp"


Presenter::Presenter():menuLoop{true},
                       mainMenu{{{mainMenu.getStartW(),       0,"Start"  },        
                                {mainMenu.getOptionsW(),     1,"Options"},        
                                {mainMenu.getRecordsW(),     2,"Records"},       
                                {mainMenu.getQuitW(),        3,"Quit"   } }},

                    optionsMenu{{ {optionsMenu.getHeightW(),          0,"Height        10"},   
                                 {optionsMenu.getWidthW(),           1,"Widht         10"},      
                                 {optionsMenu.getMinesCountW(),      2,"Mines Count   10"},     
                                 {optionsMenu.getBackW(),            3,"Back"            } }}
{
    
}

void Presenter::startMenu(){
    mainMenu.createMainMenu();
    mainMenu.highlightCursor(mainMenu.getCurrTab());
    while(menuLoop){
       actionKey = chooseAction();
       Tab currTab = mainMenu.getCurrTab();
       if(actionKey == action.down  ){
          mainMenu.moveCursor(currTab,mainMenu.getTab((currTab.second + 1 ) % 4));
       }
       else if( actionKey == action.up ){
          mainMenu.moveCursor(currTab,mainMenu.getTab((currTab.second - 1) < 0 ? currTab.second + 4 : currTab.second - 1));
       }
       else if(actionKey == action.enter ){
        if(currTab.second == 1){
            Tab currTab = optionsMenu.getCurrTab();
            optionsMenu.createOptionMenu();
            optionsMenu.highlightCursor(currTab);
            while(menuLoop){
            currTab = optionsMenu.getCurrTab();
            actionKey = chooseAction();
            if(actionKey == action.down  ){
                optionsMenu.moveCursor(currTab,optionsMenu.getTab( (currTab.second + 1 ) % 4) );
            }
            else if( actionKey == action.up ){
                optionsMenu.moveCursor(currTab,optionsMenu.getTab( (currTab.second - 1 < 0 ? currTab.second - 1 + 4 : currTab.second - 1 ))        );
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
