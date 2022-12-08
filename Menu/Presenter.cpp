#include "Presenter.hpp"


Presenter::Presenter():menuLoop{true}
{
    
}

void Presenter::startMenu(){
    mainMenu.createMainMenu();
    mainMenu.highlightCursor(mainMenu.getTab(0));
    Tab currTab = mainMenu.getCurrTab();
    while(menuLoop){
       actionKey = chooseAction();
       mvprintw(0,0,"\n%d",actionKey);
       if(actionKey == action.down  ){
          mainMenu.moveCursor(currTab,mainMenu.getTab((currTab.index + 1 ) % 4));
       }
       else if( actionKey == action.up ){
          mainMenu.moveCursor(currTab,mainMenu.getTab((currTab.index - 1) < 0 ? currTab.index + 3 : currTab.index - 1));
       }
       else if(actionKey == action.enter ){
        if(currTab.index == 1){
            mvprintw(0,0,"\n%s",currTab.name);
            optionsMenu.createOptionMenu();
            Tab currTab = optionsMenu.getTab(0);
            optionsMenu.highlightCursor(currTab);
            mvprintw(0,0,"\n%s",currTab.name);
            while(menuLoop){
            actionKey = chooseAction();
            if(actionKey == action.down  ){
                optionsMenu.moveCursor(currTab,optionsMenu.getTab( (currTab.index + 1 ) % 4) );
                mvprintw(0,0,"\ndown - %s   ",currTab.name);
            }
            else if( actionKey == action.up ){
                optionsMenu.moveCursor(currTab,optionsMenu.getTab( (currTab.index - 1 < 0 ? currTab.index + 3 : currTab.index - 1 ))        );
                mvprintw(0,0,"\nup - %s     ",currTab.name);
            }
            else if(actionKey == action.enter ){
             if(currTab.index == 3){
                mainMenu.createMainMenu();
                Tab currTab = mainMenu.getTab(1);
                mainMenu.highlightCursor(currTab);
                mvprintw(0,0,"\n%s",currTab.name);
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
        return 255;
    }
}

keyType Presenter::getPressedKey(){
    return getch();
}

Presenter::~Presenter(){

}
