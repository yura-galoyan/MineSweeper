#include "game.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>

using Cell = std::pair<int,bool>;
using Array = std::vector<Cell>;
using Matrix = std::vector<Array>;



GAME::GAME(maxCoords yx,unsigned m):height{yx.first},width{yx.second},minesCount{m}
{
  Cell tempCell;
  Array tempArray; 
  tempArray.assign(width + 2,tempCell);
  matrix.assign(height + 2,tempArray);

}





void GAME::plantBombs(){
  srand(time(0));
  for(int i = 0;i<mines_count;++i){
         matrix[ rand()%height ][  rand()%width    ] .first= 9;
  }

  while(sum(matrix) != mines_count * 9){
         matrix[ rand()%height  ][  rand()%width    ].first = 9;
  }
}

int GAME::countBombs(int i,int j){
  int temp = 0;
  if(matrix[i][j].first != 9){
    if(i > 0){
      for (int jj = j - 1;jj<=j + 1;++jj ){
        if(jj >= 0 && matrix[i - 1][jj].first == 9 &&  jj < width) {
          temp++;
        }
      }
    }
    if(matrix[i][j - 1].first == 9 && j >= 1) 
      temp++;
    if(matrix[i][j + 1].first == 9 && j < width ) 
      temp++;
    if(i < height){
      for(int jj = j - 1;jj<=j+1;++jj){
          if(jj >= 0 && matrix[i + 1][jj].first == 9 &&  jj < width)
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
     matrix[i][j].first = countBombs(i,j);

    }
  }
}

int MAP::sum(Matrix mat){
    int sum = 0;
    for(int i = 0;i<y;++i)
        for(int j = 0;j<x;++j)
    sum += mat[i][j].first;
    return sum;
}


void GAME::printClean(){
move(height + 6,2);
 for(int i = 0;i<height;++i)
        { for(int j = 0;j<width;++j){
            if(matrix[i][j].first == 0){
              printw(" ");
            }
            else if(matrix[i][j].first != 9) {
              printw("%d",matrix[i][j]);
            }
            else {
              printw("%c",char(33 + matrix[i][j].first ));
            };

            printw(" ");            
         }
        printw("\n  ");
        }
  
}



GAME::~GAME()
{
}
