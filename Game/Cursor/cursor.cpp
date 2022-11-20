#include <iostream>
#include "cursor.hpp"

enum direction{ left = 'a',right = 'd',up = 'w',down = 's',open = 'o',mark = 'm'} dir;  


CURSOR::CURSOR(int y,int x){
    this->x = x;
    this->y = y;
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


// for any pressed key
void CURSOR::interact(const int& key){
         if(left == key  /*&& canMove(left) */)
         move(left);
    else if(right == key /*&& canMove(right)*/ )
         move(right);
    else if( up   == key /*&& canMove(up)*/)
         move(up);
    else if( down == key /*&& canMove(down)*/)
         move(down);
    
    if(canTouch()){
        switch(key){
        case open:
             demine();
        case mark:
             putFlag(); 
        }
    }

    mvprintw(1,1,"%3d  %3d",i + 1,j + 1);
};

void CURSOR::move(const int& key){
    switch(key){
    case left:
        eraseCursor();
            j = (j - 1) < 0 ? j - 1 + x : (j - 1) % x  ;
            
        placeCursor();
        break;
    case right:
        eraseCursor();
            j = (j + 1)%x;
        placeCursor();
        break;
    case up:
        eraseCursor();
            i = (i - 1) < 0 ? (i - 1 + y) : (i - 1) % y;
        placeCursor();
        break;
    case down:
        eraseCursor();
            i = (i + 1)%y;
        placeCursor();
        break;
    }    
};


bool CURSOR::canTouch(){
    return false;   
}


// player puts flag,to remember that there might be a bomb
void CURSOR::putFlag(){

};

// player tries to demine a bomb
void CURSOR::demine(){

};  

