#include "Presenter.hpp"


Presenter::Presenter():menuLoop{true}
{
    
}

void Presenter::startMenu(){
    mainMenu.createMainMenu();
    mainMenu.highlightCursor(mainMenu.getTab(0));
    printw("%s",mainMenu.getCurrTab().name);
    while(menuLoop){
       actionKey = chooseAction();
       Tab currTab = mainMenu.getCurrTab();
       if(actionKey == action.down  ){
          mainMenu.moveCursor(currTab,mainMenu.getTab((currTab.index + 1 ) % 4));
       }
       else if( actionKey == action.up ){
          mainMenu.moveCursor(currTab,mainMenu.getTab((currTab.index - 1) < 0 ? currTab.index + 4 : currTab.index - 1));
       }
       else if(actionKey == action.enter ){
        if(currTab.index == 1){
            Tab currTab = optionsMenu.getCurrTab();
            optionsMenu.createOptionMenu();
            optionsMenu.highlightCursor(currTab);
            while(menuLoop){
            currTab = optionsMenu.getCurrTab();
            actionKey = chooseAction();
            if(actionKey == action.down  ){
                optionsMenu.moveCursor(currTab,optionsMenu.getTab( (currTab.index + 1 ) % 4) );
            }
            else if( actionKey == action.up ){
                optionsMenu.moveCursor(currTab,optionsMenu.getTab( (currTab.index - 1 < 0 ? currTab.index - 1 + 4 : currTab.index - 1 ))        );
            }


            else if(actionKey == action.enter ){
             if(currTab.index == 3){
                mainMenu.createMainMenu();
                mainMenu.highlightCursor(mainMenu.getCurrTab());
                break;
                }
              }
            }
        }
        else if(currTab.index == 0) {
            play = true;
            quit = false;
            mainMenu.clearScreen();
            return;
            }
        else if(currTab.index == 3) {
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
