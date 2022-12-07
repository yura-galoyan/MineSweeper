#include "board.hpp"




BOARD::BOARD(maxCoords yx):yx{yx }
{

}

void BOARD::createBoard(){
     initScreen();
     drawGameNameHeader();
    //  drawBoardHeader(yx.first,yx.second);
    //  drawBoardBody(yx.first,yx.second);

     refresh();
}

void BOARD::drawGameNameHeader(){
             mvprintw(1,62," _____  _            _____                                 \n");
             mvprintw(2,62,"|     ||_| ___  ___ |   __| _ _ _  ___  ___  ___  ___  ___ \n");
             mvprintw(3,62,"| | | || ||   || -_||__   || | | || -_|| -_|| . || -_||  _|\n");
             mvprintw(4,62,"|_|_|_||_||_|_||___||_____||_____||___||___||  _||___||_|  \n");
             mvprintw(5,62,"                                            |_|            \n");
} 

void BOARD::drawBoardHeader(){
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



void BOARD::drawBoardBody(){
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
   initscr();
   noecho();
   curs_set(0);
   use_default_colors();
   refresh();
}

BOARD::~BOARD(){

}
