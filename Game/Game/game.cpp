#include "game.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>


GAME::GAME(Coords yx,unsigned m):height{yx.first},width{yx.second},minesCount{m},
                                 gameView{yx,m},
                                 cursor{yx.first,yx.second}

                                  
{
  Cell tempCell = {0,0};
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

  plantBombs();

 
  fillMap();

}


void GAME::plantBombs(){
  srand(time(0));
  for(int i = 1;i<=minesCount;++i){
         matrix[ rand()%height + 1 ][  rand()%width + 1  ].value = 9;
  }

  while(sum(matrix) != minesCount * 9){
         matrix[ rand()%height + 1 ][  rand()%width + 1 ].value = 9;
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
             cursor.demine(ij,matrix[ij.first][ij.second].value  );
             matrix[ij.first][ij.second].state = true; 
             break;
        case CURSOR::action::mark:
             cursor.putFlag();
             break;
        }
    }

    mvprintw(1,1,"%3d  %3d",ij.first,ij.second );
};

void GAME::setPosition(Coords c){
  ij = c;
}


GAME::~GAME()
{
}
