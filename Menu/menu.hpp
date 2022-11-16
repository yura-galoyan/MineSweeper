
/*          INCLUDES          */

#include <utility>  // std::pair
#include <ncurses.h>
#include <string>

/*          INCLUDES          */

/*     ALIASES AND CONSTS     */

using coord = unsigned;
using word = std::string;

/*     ALIASES AND CONSTS     */



class MENU
{
private:
    unsigned delta = 8;
    coord overAllX; 
    
private:
    struct TABS_Y {
    coord coordY;
    WINDOW* win;
    const char * name;
} start,options,records,quit;





public:
    MENU();
    void startNcurses();
    void createMenu();
    void setUpBoardSize();
    void initStart();
    void initOptions();
    void initRecords();
    void initQuit();
    void initTabs();
    void printCenteredText(WINDOW *, const char *text);
    void drawTab(WINDOW * win,const char*);
    ~MENU();

};
