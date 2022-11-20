//deminer A.K.A. player
#include <ncurses.h>
#define CURS_COLOR 1
#define cursOFF() curs_set(0)
class CURSOR{


public:
    CURSOR(int,int);

public:
    void cursorColor_begin(); // makes cursor colorfull
    void cursorColor_end(); // makes cursor colorless again
    void placeCursor(); // creates cursor at cords
    void eraseCursor(); // erases cursor at latest cords
    void interact(const int& key); // for any pressed key
    void move(const int& key); // left, right, up, down
    void putFlag(); // player puts flag,to remember that there might be a bomb
    void demine();  // player tries to demine a bomb
    bool canTouch(); // checks if cell isn't open

private:
    int i = 0,
        j = 0;
    int x,y; //coordinates
    int y0 = 12; // up left coordiantes
    int x0 = 7; // up left coordiantes
private:
    bool state; // shows if cell is opened or closed
};