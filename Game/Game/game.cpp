#include "game.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>

GAME::GAME(Coords yx,unsigned m):height{yx.first},width{yx.second},minesCount{m},playeMineCounter{m},
                                 gameView{yx,m},
                                 cursor{yx.first,yx.second}

                                  
{
  Cell tempCell = {0,0,1};
  Array tempArray; 
  tempArray.assign(width + 2,tempCell);
  matrix.assign(height + 2,tempArray);

  map = newwin(yx.first * 2 + 2,yx.second * 2 + 3,9,5);
  cursor.initCursorForWin(map,ij);
  gameView.setGameView(map);
}

void GAME::initGameView(){
  gameView.createGameView();
  cursor.initCursorForWin(map,ij);
  cursor.placeCursor();
  wrefresh(map);
}


void GAME::plantBombs(){
         int count = 0;
  while(sum(matrix) != minesCount * 9 ){
         int i = rand()%height + 1;
         int j = rand()%width + 1;
         matrix[ i ][ j ].value = 9;
  }
}

int GAME::countBombs(int i,int j){
  int temp = 0;
  if(matrix[i][j].value!= 9){
    for(int a = i - 1;a <= i + 1;++a ){
      for(int b = j - 1;b<= j + 1;++b){
        if(a == i && b == j){ }
        else if(matrix[a][b].value == 9)
          temp++;
      } 
    }
    return temp;
  }


    return 9;
}

void GAME::fillMap(){
  for(int i = 1;i<=height;++i){
    for(int j = 1;j<=width;++j){
     matrix[i][j].value = countBombs(i,j);
    }
  }
}

int GAME::sum(Matrix mat){
    int sum = 0;
    for(int i = 0; i <= height; ++i)
        for(int j = 0; j <= width; ++j)
    sum += mat[i][j].value;
    return sum;
}


void GAME::proccess(const int& key){
  if(key == CURSOR::action::left || key == CURSOR::action::right || key == CURSOR::action::up || key == CURSOR::action::down){
        cursor.moveTo(key);
  }
  else if( key == CURSOR::action::open || key == CURSOR::action::flag ){
    if(gameIsStarted())
      chooseAction(key);
  }
    
  ij = cursor.getCursorPosition();

  mvprintw(8,23,"%03d",playeMineCounter);    


  mvprintw(1,1,"%3d  %3d  h = %3d,w =  %3d,mc =  %3d",ij.first,ij.second,height,width,minesCount   );
};

void GAME::chooseAction(const int& key){
  if( key == CURSOR::action::open && !(matrix[ij.first][ij.second].isOpened) ){
    cursor.demine(ij,matrix[ij.first][ij.second].value);
    reveal(matrix,ij.first,ij.second);
  }
  else if( key == CURSOR::action::flag  && !matrix[ij.first][ij.second].isOpened){
    if(matrix[ij.first][ij.second].isNotMarked){
      cursor.mark();
      playeMineCounter--;
      matrix[ij.first][ij.second].isNotMarked = false;
    }
    else{
      cursor.unMark();
      playeMineCounter++;
      matrix[ij.first][ij.second].isNotMarked = true;
    }
  
  }


}

void GAME::printMatrix(const Matrix matrix,Coords startintPoint){
  for(int i = 1;i< matrix.size();i++){
    for(int j = 1;j<matrix[0].size();j++){
      if(matrix[i][j].value == 9 ) mvprintw(i + startintPoint.first,j*2 + startintPoint.second,"%d",matrix[i][j].value);
      else mvprintw(i + startintPoint.first,j*2 + startintPoint.second," ");
   }
  }
}


void GAME::start(){
  plantBombs();
  fillMap();
  setGameState(true);

  reveal(matrix,ij.first,ij.second);
};

void GAME::reveal(Matrix &matrix,int i,int j){
    noecho();
    if(i < 1 || j < 1 || i > matrix.size() - 2 || j > matrix[0].size() - 2){
        return;
    }
    else{
      if(0 <= matrix[i][j].value && matrix[i][j].value <= 8  && !(matrix[i][j].isOpened) ){
          cursor.demine({i,j},matrix[i][j].value);
          matrix[i][j].isOpened = true;
          usleep(5000);
      }
      if(matrix[i][j].value == 0){
        for(int a = i - 1;a<=i+ 1;++a){
          for(int b = j - 1;b <= j + 1;++b){
            if( !( a == i && b == j) && !matrix[a][b].isOpened && 0 <= matrix[a][b].value <= 8 ){
              reveal(matrix,a,b);
            }
          }
        }
      }
    }    
}

void GAME::setGameState(const bool isOpened){
  gameState = isOpened;
}

Coords GAME::getCurrentPosition(){
  return ij;
}

void GAME::setPosition(Coords c){
  ij = c;
}


GAME::~GAME()
{
  
}
