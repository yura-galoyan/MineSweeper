#include "menu_controller.hpp"



MENUCONTROLLER::MENUCONTROLLER():menuIsActive{true}
{
    
}

void MENUCONTROLLER::startMenu(){
    mainMenuView.createMainMenu();
    mainMenuView.highlightCursor(mainMenuModel.getTab(0));
    Tab currTab = mainMenuModel.getCurrTab();
    while(menuIsActive){
       actionKey = chooseAction();
       if(actionKey == action.down  ){
          mainMenuView.moveCursor(currTab,mainMenuModel.getTab( (currTab.index + 1 ) % 4));
       }
       else if( actionKey == action.up ){
          mainMenuView.moveCursor(currTab,mainMenuModel.getTab( (currTab.index - 1) < 0 ? currTab.index + 3 : currTab.index - 1));
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

void MENUCONTROLLER::enterOptionsSubMenu(){
        optionsMenuView.createOptionMenu();
        Tab currTab = optionsMenuModel.getTab(0);
        optionsMenuView.highlightCursor(currTab,optionsMenuModel.getOptionValue(currTab));
        while(menuIsActive){
            actionKey = chooseAction();
            if(actionKey == action.down  ){
                optionsMenuView.moveCursor(currTab,optionsMenuModel.getTab( (currTab.index + 1 ) % 4) );
            }
            else if( actionKey == action.up ){
                optionsMenuView.moveCursor(currTab,optionsMenuModel.getTab( (currTab.index - 1 < 0 ? currTab.index + 3 : currTab.index - 1 ))        );
            }
            else if( actionKey == action.right){
                optionsMenuModel.changeValue(currTab.index,incValue);
            }
            else if( actionKey == action.left){
                optionsMenuModel.changeValue(currTab.index,decValue);
            }
            else if(actionKey == action.enter ){
                if(currTab.index == 3){
                    mainMenuView.createMainMenu();
                    Tab currTab = mainMenuModel.getTab(1);
                    mainMenuView.highlightCursor(currTab);
                    break;
                }
            }
            if(currTab.index != 3){
                optionsMenuView.highlightCursor(currTab,optionsMenuModel.getOptionValue(currTab));
            }
        }
}





void MENUCONTROLLER::startGame(){
    play = true;
    quit = false;
    mainMenuView.clearScreen();
}

void MENUCONTROLLER::endGame(){
    play = false;
    quit = true;
}

keyType MENUCONTROLLER::chooseAction(){
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

keyType MENUCONTROLLER::getPressedKey(){
    return getch();
}


Coords MENUCONTROLLER::getYX(){
    return optionsMenuModel.getYX();
};

unsigned MENUCONTROLLER::getMC(){
    return optionsMenuModel.getMC();
}

MENUCONTROLLER::~MENUCONTROLLER(){

}