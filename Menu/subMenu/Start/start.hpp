#include <string>
#include <ncurses.h>

using line = std::string;

class START :
{
private:
    line name;
    WINDOW* start{};
public:
    START(line text,int y,int x);






    ~START();
};
