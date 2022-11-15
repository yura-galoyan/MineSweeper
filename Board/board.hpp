/*          INCLUDES          */

#include <utility>  // std::pair
#include <ncurses.h>




/*          INCLUDES          */

/*     ALIASES AND CONSTS     */

const auto& printCh = addch;
const auto UpLeftCorner   = ACS_ULCORNER;
const auto UpRightCorner  = ACS_URCORNER;
const auto LowLeftCorner  = ACS_LLCORNER;
const auto LowRightCorner = ACS_LRCORNER;
const auto HorizontalLine = ACS_HLINE;
const auto VerticalLine   = ACS_VLINE;
const auto LeftCross      = ACS_LTEE;
const auto RightCross     = ACS_RTEE;

/*          ALIASES           */
using coord = std::pair<unsigned,unsigned>;

class BOARD{
private:
    coord xy;

public:
    BOARD();
    void startNcurses();
    void initializeWindow();




    ~BOARD();
};
