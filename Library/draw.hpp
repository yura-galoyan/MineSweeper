
#include "libraries.hpp"

namespace DRAW{
   void drawTab(WINDOW * win,const char* text);
   void printCenteredText(WINDOW * win, const char *text);
   void drawGameNameHeader();
   void drawOptionsHeader();
   void drawBoardHeader(unsigned y,unsigned x);
   void drawBoardBody(unsigned y,unsigned x);
}
