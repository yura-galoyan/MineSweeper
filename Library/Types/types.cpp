#include <ncurses.h>

using window = WINDOW*;

//TODO: Put this into MENU class
class triple{
public:
    window win;
    int second;
    const char* name;
public:
   triple(window f = stdscr,int s = 1,const char*t = "\0"){
       win = f;
       second = s;
       name = t;
   }




};