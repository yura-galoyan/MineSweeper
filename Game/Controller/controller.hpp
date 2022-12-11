#include "../Game/game.hpp"

#define cursOFF() curs_set(0)


class CONTROLLER
{
private:
    GAME game;
    
private:
    bool gameActive;
public:
    CONTROLLER(Coords,unsigned);

    void startGame();
    int getPressedKey();
    ~CONTROLLER();
};


