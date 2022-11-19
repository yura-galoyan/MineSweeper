#include <utility>  // std::pair
#include <ncurses.h>




#define UpLeftCorner    ACS_ULCORNER
#define UpRightCorner   ACS_URCORNER
#define LowLeftCorner   ACS_LLCORNER
#define LowRightCorner  ACS_LRCORNER
#define HorizontalLine  ACS_HLINE
#define VerticalLine    ACS_VLINE
#define LeftCross       ACS_LTEE
#define RightCross      ACS_RTEE

/*          ALIASES           */
using coords= std::pair<unsigned,unsigned>;

class BOARD{
private:
    coords yx;

public:
    BOARD(coords);
    void startNcurses();
    void createBoard();



    ~BOARD();
};
