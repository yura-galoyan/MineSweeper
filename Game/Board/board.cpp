#include "board.hpp"




BOARD::BOARD(coords yx):yx{yx }
{

}

void BOARD::createBoard(){
  startNcurses();
  
//      DRAW::drawGameNameHeader();
//      DRAW::drawBoardHeader(yx.first,yx.second);
//      DRAW::drawBoardBody(yx.first,yx.second);

//  refresh();
}

void BOARD::drawBoardHeader(){
  //FIXME: WRAP ALL THIS
  // int posY = 7,
  //     posX = 5;
  // move(posY,posX);
  // addch(ACS_ULCORNER);
  // for(int j = 0;j<2*yx.second + 1;++j){
  //   addch(HorizontalLine);
  // }  
  // addch(UpRightCorner);
  // posY++;
  // move(posY,posX);
  // addch(VerticalLine);
  // printw(" 00:00(x_x)(o.O)[000]");
  // move(posY,2*yx.second +3 + posX - 1);
  // addch(VerticalLine);
  // posY++;
  // move(posY,posX);
  // addch(LeftCross);
  // for(int j = 0;j<2*yx.second + 1;++j){
  //   addch(HorizontalLine);
  // }
  // addch(RightCross);

}


//    void BOARD::printCenteredText(WINDOW * win, const char *text){
//        std::string ex = text;
//        coord halfX = win->_maxx/2 - ex.length()/2;
//        coord halfY = win->_maxy/2;
//        mvwprintw(win,halfY,halfX,"%s",text);
//    }

void BOARD::drawBoardBody(){
//FIXME: CHANGE ALL THIS PLEASE THIS LOOK TERRIBLE
//  int posY = 9,posX = 5;
//  for(int i = 0;i<yx.first;++i){//2
//    posY++;
//    move(posY,posX);
//    addch(VerticalLine);
//    for(int j = 0;j< yx.second;++j){//1
//      printw(" #");  
//    }
//    printw(" ");
//    addch(VerticalLine);
//  }
//  posY++;
//  move(posY,posX);
//  addch(LowLeftCorner);
//  for(int j = 0;j<yx.second*2 + 1;++j){//1
//    addch(HorizontalLine);
//  }  
//  addch(LowRightCorner);
}


void BOARD::initScreen(){
//    initscr();
//    noecho();
//    curs_set(0);
//    use_default_colors();
//    refresh();
}

BOARD::~BOARD(){

}
