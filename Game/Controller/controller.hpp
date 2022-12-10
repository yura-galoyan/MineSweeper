#include "../Board/board.hpp"
#include "../Cursor/cursor.hpp"
#include "../Game/game.hpp"
class CONTROLLER
{
private:
    BOARD board;
    CURSOR cursor;
    GAME game;
    
private:
    bool gameActive;
public:
    CONTROLLER(maxCoords,unsigned);

    void startGame();
    int getPressedKey();
    ~CONTROLLER();
};


