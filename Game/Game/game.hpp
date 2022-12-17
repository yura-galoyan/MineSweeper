#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>

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
    bool isMarked = false;
    Matrix matrix;

private:
    GAMEVIEW gameView;
    CURSOR cursor;
private:
    Coords ij = {1,1};
    window map;

public:
    inline bool gameIsStarted(){
        return gameState;
    }
    void setGameState(const bool isOpened);

public:
    GAME(Coords,unsigned);

public:
    void proccess(const int& key); // for any pressed key
    void chooseAction(const int& key);
    void start();

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
    void initGameView();
    void reveal(Matrix&,int,int);
    
    ~GAME();
};
