#include <iostream>
#include "cursor.hpp"
#include <ncurses.h>
enum direction{ left = 'a',right = 'd',up = 'w',down = 's',open = 'o',mark = 'm'} dir;  


CURSOR::CURSOR(int maxy,int maxx){
    this->maxx = maxx;
    this->maxy = maxy;
};

void CURSOR::cursorColor_begin(){
    start_color();
    use_default_colors();
    init_pair(CURS_COLOR,COLOR_GREEN,-1);
    attron(COLOR_PAIR(CURS_COLOR));
};

void CURSOR::cursorColor_end(){
    attroff(COLOR_PAIR(CURS_COLOR));
    refresh();
}



void CURSOR::placeCursor(){
    noecho();
    cursOFF(); 
    cursorColor_begin();
    mvprintw(i + 10, 2*j + 6,"[");
    mvprintw(i + 10, 2*j + 8,"]");
    cursorColor_end();
}

void CURSOR::eraseCursor(){
    mvprintw(i + 10,2*j + 6," ");
    mvprintw(i + 10,2*j + 8," ");
}


// for anmaxy pressed kemaxy
void CURSOR::interact(const int& kemaxy){
         if( kemaxy == left )
         move(left);
    else if( kemaxy == right )
         move(right);
    else if( kemaxy == up )
         move(up);
    else if( kemaxy == down )
         move(down);
    
    if(canTouch()){
        switch(kemaxy){
        case open:
             demine();
        case mark:
             putFlag(); 
        }
    }

    mvprintw(1,1,"%3d  %3d",i + 1,j + 1);
};

void CURSOR::move(const int& kemaxy){
    switch(kemaxy){
    case left:
        eraseCursor();
            j = (j - 1) < 0 ? j - 1 + maxx : (j - 1) % maxx  ;
            
        placeCursor();
        break;
    case right:
        eraseCursor();
            j = (j + 1)%maxx;
        placeCursor();
        break;
    case up:
        eraseCursor();
            i = (i - 1) < 0 ? (i - 1 + maxy) : (i - 1) % maxy;
        placeCursor();
        break;
    case down:
        eraseCursor();
            i = (i + 1)%maxy;
        placeCursor();
        break;
    }    
};


bool CURSOR::canTouch(){
    return false;   
}


// plamaxyer puts flag,to remember that there might be a bomb
void CURSOR::putFlag(){

};

// plamaxyer tries to demine a bomb
void CURSOR::demine(){

};  

