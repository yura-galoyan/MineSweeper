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
       if(actionKey == action.down  ){
          mainMenu.moveCursor(currTab,mainMenu.getTab( (currTab.index + 1 ) % 4));
       }
       else if( actionKey == action.up ){
          mainMenu.moveCursor(currTab,mainMenu.getTab( (currTab.index - 1) < 0 ? currTab.index + 3 : currTab.index - 1));
       }
       else if(actionKey == action.enter ){
        if(currTab.index == 3) {
            endGame();
            return;
        }
        else if(currTab.index == 0) {
            startGame();
            return;
        }
        else if(currTab.index == 1){
            enterOptionsSubMenu();
        }
      }
    }
}

void Presenter::enterOptionsSubMenu(){
        optionsMenu.createOptionMenu();
        Tab currTab = optionsMenu.getTab(0);
        optionsMenu.highlightCursor(currTab,optionsMenu.getOptionValue(currTab));
        while(menuLoop){
            actionKey = chooseAction();
            if(actionKey == action.down  ){
                optionsMenu.moveCursor(currTab,optionsMenu.getTab( (currTab.index + 1 ) % 4) );
            }
            else if( actionKey == action.up ){
                optionsMenu.moveCursor(currTab,optionsMenu.getTab( (currTab.index - 1 < 0 ? currTab.index + 3 : currTab.index - 1 ))        );
            }
            else if( actionKey == action.right/* && optionsMenu.isNotOnLimit( optionsMenu.getOptionValue(currTab) */)
            {
                optionsMenu.changeValue(currTab.index,incValue);
            }
            else if( actionKey == action.left/* && optionsMenu.isNotOnLimit( optionsMenu.getOptionValue(currTab)*/){
                optionsMenu.changeValue(currTab.index,decValue);
            }
            else if(actionKey == action.enter ){
                if(currTab.index == 3){
                    mainMenu.createMainMenu();
                    Tab currTab = mainMenu.getTab(1);
                    mainMenu.highlightCursor(currTab);
                    break;
                }
            }
            if(currTab.index != 3){
                optionsMenu.highlightCursor(currTab,optionsMenu.getOptionValue(currTab));
            }
        }
}





void Presenter::startGame(){
    play = true;
    quit = false;
    mainMenu.clearScreen();
}

void Presenter::endGame(){
    play = false;
    quit = true;
}

keyType Presenter::chooseAction(){
    keyType key = getPressedKey();
    switch (key)
    {
    case 's':
        return action.down;
    case 'w':
        return action.up;
    case 'd':
        return action.right;
    case 'a':
        return action.left;
    case 'e':
        return action.enter;
    default:
        return 255;
    }
}

keyType Presenter::getPressedKey(){
    return getch();
}


maxCoords Presenter::getYX(){
    return optionsMenu.getYX();
};

unsigned Presenter::getMC(){
    return optionsMenu.getMC();
}

Presenter::~Presenter(){

}
