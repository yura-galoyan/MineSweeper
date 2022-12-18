#include "mainLoop.hpp"

MAINLOOP::MAINLOOP()
{

}

void MAINLOOP::startMainLoop(){
    while(isOnMainLoop){
    Presenter presenter;
    presenter.startMenu();
        if(presenter.quit){  
        endwin();
        break;
    }
    else if(presenter.play){
        CONTROLLER controller(presenter.getYX(),presenter.getMC());
        controller.startGame();    }
}
};

MAINLOOP::~MAINLOOP()
{

}
