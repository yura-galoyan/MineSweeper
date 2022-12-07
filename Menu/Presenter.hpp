#include "mainmenu.hpp"
#include "options.hpp"

using keyType = int;

class Presenter
{
private:
    MAINMENU mainMenu;
    OPTIONS optionsMenu;
private:
    keyType actionKey = 0;
    bool menuLoop;

private:
    struct actions{
        keyType down = 0;
        keyType up = 1;
        keyType enter = 2;
        } action;
public:
    Presenter();

    void startMenu();

    bool play = false;
    bool quit = false;
    
    void act(keyType);
    keyType getPressedKey();
    keyType chooseAction();
    ~Presenter();
};
