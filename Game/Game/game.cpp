#include "game.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>


GAME::GAME(Coords yx,unsigned m):height{yx.first},width{yx.second},minesCount{m},
                                 gameView{yx,m},
                                 cursor{yx.first,yx.second}

                                  
{
  Cell tempCell;
  Array tempArray; 
  tempArray.assign(width + 2,tempCell);
  matrix.assign(height + 2,tempArray);
  map = newwin(yx.first * 2 + 2,yx.second * 2 + 3,9,5);
  cursor.setCursorWin(map,ij);
  gameView.setGameView(map);
}

void GAME::startGame(){
  gameView.createGameView();
  cursor.setCursorWin(map,ij);
  cursor.placeCursor();
  wrefresh(map);
}


Coords GAME::getCurrentPosition(){
  return ij;
}

void GAME::interact(const int& key){
         if( key == CURSOR::action::left )
         cursor.move(CURSOR::action::left);
    else if( key == CURSOR::action::right )
         cursor.move(CURSOR::action::right);
    else if( key == CURSOR::action::up )
         cursor.move(CURSOR::action::up);
    else if( key == CURSOR::action::down )
         cursor.move(CURSOR::action::down);

    ij = cursor.getCursorPosition();

    if(cursor.canTouch( matrix[ij.first][ij.second])){
        switch(key){
        case CURSOR::action::open:
             cursor.demine();
             break;
        case CURSOR::action::mark:
             cursor.putFlag();
             break;
        }
      // matrix[ij.first][ij.second].value = cursor.getCellState(); 
    }



    mvprintw(1,1,"%3d  %3d",ij.first,ij.second );
};

void GAME::setPosition(Coords c){
  ij = c;
}


void GAME::plantBombs(){
  srand(time(0));
  for(int i = 0;i<minesCount;++i){
         matrix[ rand()%height ][  rand()%width    ] .value= 9;
  }

  while(sum(matrix) != minesCount * 9){
         matrix[ rand()%height  ][  rand()%width    ].value = 9;
  }
}

int GAME::countBombs(int i,int j){
  int temp = 0;
  if(matrix[i][j].value!= 9){
    if(i > 0){
      for (int jj = j - 1;jj<=j + 1;++jj ){
        if(jj >= 0 && matrix[i - 1][jj].value == 9 &&  jj < width) {
          temp++;
        }
      }
    }
    if(matrix[i][j - 1].value == 9 && j >= 1) 
      temp++;
    if(matrix[i][j + 1].value== 9 && j < width ) 
      temp++;
    if(i < height){
      for(int jj = j - 1;jj<=j+1;++jj){
          if(jj >= 0 && matrix[i + 1][jj].value == 9 &&  jj < width)
            temp++;
        }
    }
    return temp; 
  }
    return 9;
}

void GAME::fillMap(){
  for(int i = 0;i<height;++i){
    for(int j = 0;j<width;++j){
     matrix[i][j].value = countBombs(i,j);

    }
  }
}

int GAME::sum(Matrix mat){
    int sum = 0;
    for(int i = 0;i<height;++i)
        for(int j = 0;j<width;++j)
    sum += mat[i][j].value;
    return sum;
}

void GAME::printClean(){
move(height + 6,2);
 for(int i = 0;i<height;++i)
        { for(int j = 0;j<width;++j){
            if(matrix[i][j].value == 0){
              printw(" ");
            }
            else if(matrix[i][j].value != 9) {
              printw("%d",matrix[i][j].value);
            }
            else {
              printw("%c",char(33 + matrix[i][j].value ));
            };

            printw(" ");            
         }
        printw("\n  ");
        }
  
}



GAME::~GAME()
{
}
