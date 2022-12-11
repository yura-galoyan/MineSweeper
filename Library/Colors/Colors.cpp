#include "Colors.hpp"



    COLOR::COLOR(colorType c, colorType font){
        color = c;
        start_color();
        init_pair(color,font,backGround);
    }

    void COLOR::startColor(WINDOW * tab){
        wattron(tab,COLOR_PAIR(color));
    }

    void COLOR::endColor(WINDOW * tab){
        wattroff(tab,COLOR_PAIR(color));
        wrefresh(tab);
    }

    COLOR::~COLOR(){
    };