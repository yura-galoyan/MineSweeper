#include "../Menu/Presenter.hpp"
#include "../Game/Controller/controller.hpp"



class MAINLOOP
{
private:
    bool isOnMainLoop = true;
public:
    MAINLOOP();

    void startMainLoop();

    ~MAINLOOP();
};
