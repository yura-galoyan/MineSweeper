



class CONTROLLER
{
private:
    BOARD board;
    CURSOR cursor;
    GAMELOOP gameloop;

public:
    CONTROLLER();

    void startGame();
    int getPressedKey();
    ~CONTROLLER();
};


