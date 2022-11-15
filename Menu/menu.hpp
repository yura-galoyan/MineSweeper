
/*          INCLUDES          */

#include <utility>  // std::pair
#include <ncurses.h>
#include <string>

/*          INCLUDES          */

/*     ALIASES AND CONSTS     */

using coord = unsigned;
using word = std::string;
struct TABS_Y{
    coord start;
    coord options;
    coord records;
    coord quit;
} ;
/*     ALIASES AND CONSTS     */



class MENU
{
private:
    unsigned delta = 8;
    WINDOW *start, *options, *records, *quit;
    coord overAllX = getmaxx(stdscr)/4 + 62; 
    TABS_Y tab;

public:
    MENU();
    void startNcurses();
    void createMenu();
    void setUpBoardSize();
    void drawStart();
    void drawOptions();
    void drawRecords();
    void drawQuit();
    void initializeTabs();
    void printCenteredText(WINDOW *, const char *text);
    ~MENU();

};
