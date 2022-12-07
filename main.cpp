#include "Menu/Presenter.hpp"
#include "Game/Controller/controller.hpp"

int main(){
    Presenter presenter;
    presenter.startMenu();
        if(presenter.quit){  
        endwin();
        
    }
   else if(presenter.play){
        CONTROLLER controller;
        controller.startGame();
    }


}