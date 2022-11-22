#include "board.hpp"




BOARD::BOARD(maxCoords yx):yx{yx }
{

}

void BOARD::createBoard(){
  startNcurses();
  
  DRAW::drawGameNameHeader();
  DRAW::drawBoardHeader(yx.first,yx.second);
  DRAW::drawBoardBody(yx.first,yx.second);
  refresh();
}


void BOARD::startNcurses(){
    initscr();
    noecho();
    curs_set(0);
    use_default_colors();
    refresh();
}

BOARD::~BOARD(){

}
