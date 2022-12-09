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
        optionsMenu.highlightCursor(currTab);
        while(menuLoop){
        actionKey = chooseAction();
        if(actionKey == action.down  ){
            optionsMenu.moveCursor(currTab,optionsMenu.getTab( (currTab.index + 1 ) % 4) );
        }
        else if( actionKey == action.up ){
            optionsMenu.moveCursor(currTab,optionsMenu.getTab( (currTab.index - 1 < 0 ? currTab.index + 3 : currTab.index - 1 ))        );
        }
        else if( actionKey == action.right){
            
        }
        else if( actionKey == action.left){

        }
        else if(actionKey == action.enter ){
         if(currTab.index == 3){
            mainMenu.createMainMenu();
            Tab currTab = mainMenu.getTab(1);
            mainMenu.highlightCursor(currTab);
            break;
            }
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
    case 'e':
        return action.enter;
    default:
        return 255;
    }
}

keyType Presenter::getPressedKey(){
    return getch();
}

void Presenter::drawValueTab(window win,const char* text,int value){
      box(win,0,0);
      printCenteredText(win,text);
      printw(" %d",value);
      wrefresh(win);
      refresh();   
}

void MENU::printCenteredText(window win, const char *text){
      std::string ex = text;
      Coord halfX = win->_maxx/2 - ex.length()/2;
      Coord halfY = win->_maxy/2;
      mvwprintw(win,halfY,halfX,"%s",text);
}
Presenter::~Presenter(){

}
