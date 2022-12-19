#include "menuView.hpp"

MENUVIEW::MENUVIEW()
    :green(1,COLOR_GREEN)
{
   
}

void MENUVIEW::clearScreen(){
    clear();
    refresh();
}

void MENUVIEW:: moveCursor(Tab &currTab,const Tab &nextTab){
    unHighlightCursor(currTab);
    currTab = nextTab;
    highlightCursor(currTab);
}

void MENUVIEW::highlightCursor( Tab tab){
    green.startColor(tab.win);
    drawTab(tab);
    green.endColor(tab.win);
}

void MENUVIEW::unHighlightCursor(Tab tab){
    green.endColor(tab.win); 
    drawTab(tab);
}

void MENUVIEW::drawHighlightedTab(Tab tab,int value){
    green.startColor(tab.win);
    drawTab(tab,value);
    green.endColor(tab.win);
};

void MENUVIEW::printCenteredText(window win, const char *text){
      std::string ex = text;
      Coord halfX = win->_maxx/2 - ex.length()/2;
      Coord halfY = win->_maxy/2;
      mvwprintw(win,halfY,halfX,"%s",text);
}

void MENUVIEW::drawTab(Tab tab){
      wclear(tab.win);
      box(tab.win,0,0);
      printCenteredText(tab.win,tab.name);
      wrefresh(tab.win);
      refresh();
}

void MENUVIEW::drawTab(Tab tab,int value){
      box(tab.win,0,0);
      printCenteredText(tab.win,tab.name);
      wprintw(tab.win," %4d",value);
      wrefresh(tab.win);
      refresh();   
}







MENUVIEW::~MENUVIEW(){
    
}