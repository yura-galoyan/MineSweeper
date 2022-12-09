#include "mainmenu.hpp"
#include "options.hpp"

using keyType = int;

class Presenter
{


private:
    MAINMENU mainMenu;
    OPTIONS optionsMenu;
private:
    keyType actionKey;
    bool menuLoop;

private:
    keyType getPressedKey();

private:
    struct actions{
        keyType down = 0;
        keyType up = 1;
        keyType enter = 2;
        keyType right = 3;
        keyType left = 4;
        } action;


    int width = 10,
        height = 10,
        minesCount = 10;
public:
    Presenter();

    void startMenu();
    void enterOptionsSubMenu();
    void startGame();
    void endGame();
    bool play = false;
    bool quit = false;
    
    void act(keyType);
    keyType chooseAction();
    void drawValueTab(window win,const char* text,int value);
    ~Presenter();
};
