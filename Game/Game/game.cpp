#include "game.hpp"
GAME::GAME(Coords yx,unsigned m):height{yx.first},width{yx.second},minesCount{m},playeMineCounter{m},
                                 gameView{yx,m},
                                 cursor{yx.first,yx.second}

                                  
{
  initMatrix();
  map = newwin(yx.first * 2 + 2,yx.second * 2 + 3,9,5);
  cursor.initCursor(map,ij);
  gameView.setGameView(map);
}

void GAME::initMatrix(){
  Cell tempCell = {0,0,1};
  Array tempArray; 
  tempArray.assign(width + 2,tempCell);
  matrix.assign(height + 2,tempArray);
}

void GAME::initGameView(){
  gameView.createGameView();
  cursor.initCursor(map,ij);
  cursor.placeCursor();
  wrefresh(map);
}

void GAME::initTime(){
  old = std::chrono::steady_clock::now();
}


void GAME::plantBombs(){
         int count = 0;
  while(sum(matrix) != minesCount * 9 ){
    
         int i = rand()%height + 1;
         int j = rand()%width + 1;
         if( i != ij.first || j != ij.second)
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
    if(isStarted())
      chooseAction(key);
  }
  updateIJ();
  printMineCount(); 
  if(isStarted()){ 
  countAndPrintTime();
  }  
};

void GAME::updateIJ(){
  ij = cursor.getCursorPosition();
}

void GAME::printMineCount(){
  mvprintw(8,23,"%03d",playeMineCounter);
}

void GAME::countAndPrintTime(){
  auto dur = std::chrono::steady_clock::now() - old;
  mvprintw(8,7,"%ld",std::chrono::duration_cast<std::chrono::seconds>(dur).count() );
}

void GAME::chooseAction(const int& key){
  if( key == CURSOR::action::open && !(matrix[ij.first][ij.second].isOpened) ){ 
      if( matrix[ij.first][ij.second].value == 9 ){
      gameOver = true;
      return;
    }
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

void GAME::start(){
  plantBombs();
  fillMap();
  initTime();
  if(matrix[ij.first][ij.second].value != 9){
  setGameState(true);
  reveal(matrix,ij.first,ij.second);
  }
  else gameOver = true;
};

bool GAME::isWin(){
  if(height * width - numberOfOpenedCells == minesCount){
    return true;
  }
  else 
    return false;
}

bool GAME::isLost(){
  return gameOver;
}



void GAME::reveal(Matrix &matrix,int i,int j){
    noecho();
    if(i < 1 || j < 1 || i > matrix.size() - 2 || j > matrix[0].size() - 2){
        return;
    }
    else{
      if(0 <= matrix[i][j].value && matrix[i][j].value <= 8  && !(matrix[i][j].isOpened) ){
          cursor.demine({i,j},matrix[i][j].value);
          numberOfOpenedCells++;
          matrix[i][j].isOpened = true;
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

void GAME::revealAllBombs(){
  for(int i = 1;i<=matrix.size() - 2;++i){
    for(int j = 1;j<=matrix[0].size() - 2;++j){
      if(matrix[i][j].value == 9){
        cursor.printColoredString({i,j},"*",COLOR{6,COLOR_RED});
        usleep(15000);
        }
    }
  }
  gameView.printGameOverHeader(labelPosition);
}

void GAME::endGame(){
  gameView.printYouWinHeader(labelPosition);
}

void GAME::waitUntillInput(){
  nodelay(stdscr,false);
  mvprintw(2,2,"Press any key to continue...");
  getch();
  clear();
}


void GAME::setGameState(const bool state){
  gameState = state;
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
