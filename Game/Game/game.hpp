#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <chrono>
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
    int labelPosition = 1;
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
    std::chrono::_V2::steady_clock::time_point old;

public:
    inline bool isStarted(){
        return gameState;
    }
    void setGameState(const bool );

public:
    GAME(Coords,unsigned);
    void proccess(const int& key); // for any pressed key
    void chooseAction(const int& key);
    void start();
    bool isWin();
    bool isLost();
    void plantBombs();
    int sum(Matrix);
    void fillMap();
    int countBombs(int,int);
    void setPosition(Coords);
    void initTime();
    void initMatrix();
    void waitUntillInput();
    void initView();
    void countAndPrintTime();
    void reveal(Matrix&,int,int);
    void revealAllBombs();
    void endGame();
    void updateIJ();
    void printMineCount();
    
    ~GAME();
};
