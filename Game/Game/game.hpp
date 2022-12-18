#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "../GameView/gameView.hpp"
#include "../Cursor/cursor.hpp"

using Array = std::vector<Cell>;
using Matrix = std::vector<Array>;
using window = WINDOW *;
class GAME{
private:
    unsigned height,
             width,
             minesCount;
    int playeMineCounter;

    bool gameState = false;
    bool gameOver = false;

    int numberOfOpenedCells = 0;
    Matrix matrix;

private:
    GAMEVIEW gameView;
    CURSOR cursor;
private:
    Coords ij = {1,1};
    window map;

public:
    inline bool isStarted(){
        return gameState;
    }

    void setGameState(const bool );

public:
    GAME(Coords,unsigned);

public:
    void proccess(const int& key); // for any pressed key
    void chooseAction(const int& key);
    void start();
    bool isWin();
    bool isOver();

public:
    void plantBombs();
    int sum(Matrix);
    void fillMap();
    int countBombs(int,int);

public:
    void setPosition(Coords);
    Coords getCurrentPosition();

public:
    void printClean();
    void printMatrix(const Matrix matrix,Coords startintPoint);
    
    void printGameOverHeader(int);
    void printYouWinHeader(int);
    
    void initGameView();
    void reveal(Matrix&,int,int);
    void setNumberOfOpenedCells(int );
    
    ~GAME();
};
