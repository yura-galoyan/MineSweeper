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
    Matrix matrix;

private:
    GAMEVIEW gameView;
    CURSOR cursor;
private:
    Coords ij = {1,1};

    window map;



public:
    GAME(Coords,unsigned);
    void interact(const int& key); // for any pressed key
    void fillMap();
    void plantBombs();
    void printClean();
    void setPosition(Coords);
    Coords getCurrentPosition();
    void startGame();
    void reveal(Matrix&,int,int);
    int countBombs(int,int);
    int sum(Matrix);

    ~GAME();
};
