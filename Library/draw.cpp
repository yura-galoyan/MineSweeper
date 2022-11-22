#include "draw.hpp"


void DRAW::drawTab(WINDOW * win,const char* text){
    box(win,0,0);
    printCenteredText(win,text);
    wrefresh(win);
    refresh();
}

void DRAW::printCenteredText(WINDOW * win, const char *text){
    std::string ex = text;
    coord halfX = win->_maxx/2 - ex.length()/2;
    coord halfY = win->_maxy/2;
    mvwprintw(win,halfY,halfX,"%s",text);
}

void DRAW::drawGameNameHeader(){
    mvprintw(1,62," _____  _            _____                                 \n");
    mvprintw(2,62,"|     ||_| ___  ___ |   __| _ _ _  ___  ___  ___  ___  ___ \n");
    mvprintw(3,62,"| | | || ||   || -_||__   || | | || -_|| -_|| . || -_||  _|\n");
    mvprintw(4,62,"|_|_|_||_||_|_||___||_____||_____||___||___||  _||___||_|  \n");
    mvprintw(5,62,"                                            |_|            \n");
}

void DRAW::drawOptionsHeader(){
    mvprintw(1,62," _____       _    _                \n");
    mvprintw(2,62,"|     | ___ | |_ |_| ___  ___  ___ \n");
    mvprintw(3,62,"|  |  || . ||  _|| || . ||   ||_ -|\n");
    mvprintw(4,62,"|_____||  _||_|  |_||___||_|_||___|\n");
    mvprintw(5,62,"       |_|                         \n");
}

void DRAW::drawBoardHeader(unsigned y,unsigned x){

  int posY = 7,
      posX = 5;
  maxCoords yx = {y,x};
  move(posY,posX);
  addch(ACS_ULCORNER);
  for(int j = 0;j<2*yx.second + 1;++j){//1
    addch(HorizontalLine);
  }  
  addch(UpRightCorner);
  posY++;
  move(posY,posX);
  addch(VerticalLine);
  printw(" 00:00(x_x)(o.O)[000]");
  move(posY,2*yx.second +3 + posX - 1);//1
  addch(VerticalLine);
  posY++;
  move(posY,posX);
  addch(LeftCross);
  for(int j = 0;j<2*yx.second + 1;++j){//1
    addch(HorizontalLine);
  }
  addch(RightCross);

}

void DRAW::drawBoardBody(unsigned y,unsigned x){

  int posY = 9,posX = 5;
  maxCoords yx = {y,x};
  for(int i = 0;i<yx.first;++i){//2
    posY++;
    move(posY,posX);
    addch(VerticalLine);
    for(int j = 0;j< yx.second;++j){//1
      printw(" #");  
    }
    printw(" ");
    addch(VerticalLine);
  }
  posY++;
  move(posY,posX);
  addch(LowLeftCorner);
  for(int j = 0;j<yx.second*2 + 1;++j){//1
    addch(HorizontalLine);
  }  
  addch(LowRightCorner);
}

