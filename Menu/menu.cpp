#include "menu.hpp"

MENU::MENU()
    :green(COLOR_GREEN,-1 ) 
{

}

void MENU::initTab(MENUTABS &tab, Coord Y,const char * text){
    tab.coordY = Y;
    tab.name = text;
   tab.win = newwin(7,60,Y,overAllX);
}
void MENU::clearScreen(){
    clear();
    refresh();
}

void MENU::moveCursor(Tab &currTab,const Tab &nextTab){
    unHighlightCursor(currTab);
    currTab = nextTab;
    highlightCursor(currTab);
}

void MENU::highlightCursor(const Tab &tab){
    green.startColor(tab.win);
    drawTab(tab.win,tab.name);
}

void printCenteredText(WINDOW * win, const char *text){
      std::string ex = text;
      Coord halfX = win->_maxx/2 - ex.length()/2;
      Coord halfY = win->_maxy/2;
      mvwprintw(win,halfY,halfX,"%s",text);
}
void MENU::drawTab(WINDOW * win,const char* text){
      box(win,0,0);
      printCenteredText(win,text);
      wrefresh(win);
      refresh();
}



Tab MENU::getCurrTab(){
    return currTab;
}

void MENU::unHighlightCursor(Tab &tab){
    green.endColor(tab.win); 
    drawTab(tab.win,tab.name);
}
