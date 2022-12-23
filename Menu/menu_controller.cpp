#include "menu_controller.hpp"



MENUCONTROLLER::MENUCONTROLLER():menuIsActive{true}
{
    
}

void MENUCONTROLLER::startMenu(){
    mainMenuView.createMainMenu(mainMenuModel.getMenuList());
    mainMenuView.highlightCursor(mainMenuModel.getTab(0));
    Tab currTab = mainMenuModel.getCurrTab();
    while(menuIsActive){
       actionKey = chooseAction();
       if(actionKey == DOWN  ){
          mainMenuView.moveCursor(currTab,mainMenuModel.getTab( (currTab.index + 1 ) % 4));
       }
       else if( actionKey == UP ){
          mainMenuView.moveCursor(currTab,mainMenuModel.getTab( (currTab.index - 1) < 0 ? currTab.index + 3 : currTab.index - 1));
       }
       else if(actionKey == ENTER ){
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
    optionsMenuView.createOptionMenu(optionsMenuModel.getMenuList());
    Tab currTab = optionsMenuModel.getTab(0);
    optionsMenuView.highlightCursor(currTab,optionsMenuModel.getOptionValue(currTab));
    while(menuIsActive){
        actionKey = chooseAction();
        if(actionKey == DOWN  ){
            optionsMenuView.moveCursor(currTab,optionsMenuModel.getTab( (currTab.index + 1 ) % 4) );
        }
        else if( actionKey == UP ){
            optionsMenuView.moveCursor(currTab,optionsMenuModel.getTab( (currTab.index - 1 < 0 ? currTab.index + 3 : currTab.index - 1 ))        );
        }
        else if( actionKey == RIGHT){
            optionsMenuModel.changeValue(currTab.index,incValue);
        }   
        else if( actionKey == LEFT){
            optionsMenuModel.changeValue(currTab.index,decValue);
        }
        else if(actionKey == ENTER ){
            if(currTab.index == 3){
                mainMenuView.createMainMenu(mainMenuModel.getMenuList());
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
    playIsPressed = true;
    quitIsPressed = false;
    mainMenuView.clearScreen();
}

void MENUCONTROLLER::endGame(){
    playIsPressed = false;
    quitIsPressed = true;
}

keyType MENUCONTROLLER::chooseAction(){
    keyType key = getPressedKey();
    switch (key)
    {
    case DOWN:
        return DOWN;
    case UP:
        return UP;
    case RIGHT:
        return RIGHT;
    case LEFT:
        return LEFT;
    case ENTER:
        return ENTER;
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
