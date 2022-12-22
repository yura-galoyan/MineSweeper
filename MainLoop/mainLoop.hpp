#include "../Menu/menu_controller.hpp"
#include "../Game/Controller/game_controller.hpp"



class MAINLOOP
{
private:
    bool isOnMainLoop = true;
public:
    MAINLOOP();

    void start();
    void exit();
    ~MAINLOOP();
};
