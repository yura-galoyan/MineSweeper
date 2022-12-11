#include "menu.hpp"

MENU::MENU()
    :green(COLOR_GREEN)
{
   
}

Tab MENU::initTab(const Coord i ,const Coord Y,const char * text){
    Tab tab;
    tab.coordY = Y;
    tab.name = text;
    tab.index = i;
    tab.win = newwin(5,45,Y,overAllX);
    return tab;
}
void MENU::clearScreen(){
    clear();
    refresh();
}

void MENU:: moveCursor(Tab &currTab,const Tab &nextTab){
    unHighlightCursor(currTab);
    currTab = nextTab;
    highlightCursor(currTab);
}

void MENU::highlightCursor( Tab tab){
    green.startColor(tab.win);
    drawTab(tab);
    green.endColor(tab.win);
}



void MENU::unHighlightCursor(Tab tab){
    green.endColor(tab.win); 
    drawTab(tab);
}

void MENU::drawHighlightedTab(Tab tab,int value){
    green.startColor(tab.win);
    drawTab(tab,value);
    green.endColor(tab.win);
};

void MENU::printCenteredText(window win, const char *text){
      std::string ex = text;
      Coord halfX = win->_maxx/2 - ex.length()/2;
      Coord halfY = win->_maxy/2;
      mvwprintw(win,halfY,halfX,"%s",text);
}

void MENU::drawTab(Tab tab){
      wclear(tab.win);
      box(tab.win,0,0);
      printCenteredText(tab.win,tab.name);
      wrefresh(tab.win);
      refresh();
}

void MENU::drawTab(Tab tab,int value){
      box(tab.win,0,0);
      printCenteredText(tab.win,tab.name);
      wprintw(tab.win," %d",value);
      wrefresh(tab.win);
      refresh();   
}

void MENU::changeHighlightedTab(Tab tab,int value){
    
}
Tab MENU::getCurrTab(){
    return currTab;
}

window MENU::getWin(const int &i){
   return this->menuList[i].win;
}



MENU::~MENU(){
    
}