#include <ncurses.h>
#include <utility>
#include <vector>
#include "../GameView/gameView.hpp"
#include "../Cursor/cursor.hpp"
using Cell = pair<int,bool>;
using Array = std::vector<Cell>;
using Matrix = std::vector<Array>;

using window = WINDOW *;
class GAME{

private:
    unsigned height,
             width,
             minesCount;
    bool gameState = false;
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
    void setGameState(const bool state);

public:
    GAME(Coords,unsigned);
    void proccess(const int& key); // for any pressed key
    void chooseAction(const int& key);
    void fillMap();
    void plantBombs();
    void printClean();
    void setPosition(Coords);
    Coords getCurrentPosition();
    void printMatrix(const Matrix matrix,Coords startintPoint);
    void initGameView();
    void start();
    void reveal(Matrix&,int,int);
    int countBombs(int,int);
    int sum(Matrix);
    
    ~GAME();
};
