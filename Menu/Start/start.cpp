#include "start.hpp"





START::START(line text,int y,int x){
    name = text;
    start = newwin(7,60,tab.start,overAllX);
}

START::~START(){

}
