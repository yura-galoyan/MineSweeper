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
  mvprintw(1,90," _____  _            _____                                 \n");
  mvprintw(2,90,"|     ||_| ___  ___ |   __| _ _ _  ___  ___  ___  ___  ___ \n");
  mvprintw(3,90,"| | | || ||   || -_||__   || | | || -_|| -_|| . || -_||  _|\n");
  mvprintw(4,90,"|_|_|_||_||_|_||___||_____||_____||___||___||  _||___||_|  \n");
  mvprintw(5,90,"                                            |_|            \n");
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
  printw("       (o.O)  [     ]");
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


void GAMEVIEW::printGameOverHeader(int y){
  lose.startColor(stdscr);
  mvprintw(y,    32," _____ _____ _____ _____   _____ _____ _____ _____");
  mvprintw(y + 1,32,"|   __|  _  |     |   __| |     |  |  |   __| __  |");
  mvprintw(y + 2,32,"|  |  |     | | | |   __| |  |  |  |  |   __|    -|");
  mvprintw(y + 3,32,"|_____|__|__|_|_|_|_____| |_____|\\___/|_____|__|__|");
  lose.endColor(stdscr);
}

void GAMEVIEW::printYouWinHeader(int y){
  win.startColor(stdscr);                              
  mvprintw(y,32,"   __ __ _____ _____    _ _ _ _____ _____ ");
  mvprintw(y + 1,32,"  |  |  |     |  |  |  | | | |     |   | |");
  mvprintw(y + 2,32,"  |_   _|  |  |  |  |  | | | |  |  | | | |");
  mvprintw(y + 3,32,"    |_| |_____|_____|  |_____|_____|_|___|");
  win.endColor(stdscr);
                 
}



void GAMEVIEW::initScreen(){
   nodelay(stdscr,true);
   initscr();
   noecho();
   use_default_colors();
   refresh();
}

GAMEVIEW::~GAMEVIEW(){

}
