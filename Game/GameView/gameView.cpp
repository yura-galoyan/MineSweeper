#include "gameView.hpp"

GAMEVIEW::GAMEVIEW(Coords yx,unsigned m):yx{yx},minesCount{m}
{

}

void GAMEVIEW::createGameView(){
     initScreen();
     drawGameNameHeader();
     drawGameViewHeader();
     drawGameViewBody();
     refresh();
}

void GAMEVIEW::drawGameNameHeader(){
             mvprintw(1,62," _____  _            _____                                 \n");
             mvprintw(2,62,"|     ||_| ___  ___ |   __| _ _ _  ___  ___  ___  ___  ___ \n");
             mvprintw(3,62,"| | | || ||   || -_||__   || | | || -_|| -_|| . || -_||  _|\n");
             mvprintw(4,62,"|_|_|_||_||_|_||___||_____||_____||___||___||  _||___||_|  \n");
             mvprintw(5,62,"                                            |_|            \n");
} 

void GAMEVIEW::drawGameViewHeader(){
  int posY = 7,
      posX = 5;
  move(posY,posX);
  addch(ACS_ULCORNER);
  for(int j = 0;j<2*yx.second + 1;++j){
    addch(ACS_HLINE);
  }  
  addch(ACS_URCORNER);
  posY++;
  move(posY,posX);
  addch(ACS_VLINE);
  printw(" 00:00(x_x)(o.O)[000]");
  move(posY,2*yx.second +3 + posX - 1);
  addch(ACS_VLINE);
  posY++;
  move(posY,posX);
  addch(ACS_LTEE);
  for(int j = 0;j<2*yx.second + 1;++j){
    addch(ACS_HLINE);
  }
  addch(ACS_RTEE);

}

void GAMEVIEW::setGameView(window w){
  map = w;
}

void GAMEVIEW::drawGameViewBody(){
  int i = 0;
 for( ;i <= yx.first; ++i){
   wmove(map,i,0);
   waddch(map,ACS_VLINE);
   for(int j = 0;j < yx.second; ++j){//1
     wprintw(map," #");  
   }
   wprintw(map," ");
   waddch(map,ACS_VLINE);
 }
 wmove(map,i,0);
 waddch(map,ACS_LLCORNER);
 for(int j = 0; j <= yx.second*2  ; ++j){//1
   waddch(map,ACS_HLINE);
 }  
 waddch(map,ACS_LRCORNER);

wrefresh(map);

}

void GAMEVIEW::initScreen(){
   initscr();
   noecho();
   use_default_colors();
   refresh();
}

GAMEVIEW::~GAMEVIEW(){

}
