#include "board.hpp"




BOARD::BOARD(/* args */){

}

void BOARD::startNcurses(){
    initscr();
    noecho();
}

void BOARD::initializeWindow(){
  startNcurses();

  int posY = 5,
      posX = 5;

  move(posY,posX);
  printCh(UpLeftCorner);
  for(int j = 0;j<2*xy.first + 1;++j){
    printCh(HorizontalLine);
  }  
  printCh(UpRightCorner);
  posY++;
  move(posY,posX);
  printCh(VerticalLine);
  printw(" 00:00(x_x)(o.O)[000]");
  move(posY,2*xy.first +3 + posX - 1);
  printCh(HorizontalLine);
  posY++;
  move(posY,posX);
  printCh(LeftCross);
  for(int j = 0;j<2*xy.first + 1;++j){
    printCh(HorizontalLine);
  }
  printCh(RightCross);
  for(int i = 0;i<xy.second;++i){
    posY++;
    move(posY,posX);
    printCh(VerticalLine);
    for(int j = 0;j< xy.first;++j){
      printw(" #");  
    }
    printw(" ");
    printCh(VerticalLine);
  }
  posY++;
  move(posY,posX);
  printCh(LowLeftCorner);
  for(int j = 0;j<xy.first*2 + 1;++j){
    printCh(HorizontalLine);
  }  
  printCh(LowRightCorner);
}


BOARD::~BOARD(){

}
