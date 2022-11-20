#pragma once

#include <string>
#include <ncurses.h>
#include <vector>
#include <utility>
#include <cstdlib>
#include "./Colors/Colors.hpp"
#include "draw.hpp"
#include "Types/types.cpp"
#include "../Game/Board/board.hpp"
#include "../Game/Cursor/cursor.hpp"
#include "../Game/Gameloop/gameloop.hpp"
#include "../Menu/menu.hpp"


#define UpLeftCorner    ACS_ULCORNER
#define UpRightCorner   ACS_URCORNER
#define LowLeftCorner   ACS_LLCORNER
#define LowRightCorner  ACS_LRCORNER
#define HorizontalLine  ACS_HLINE
#define VerticalLine    ACS_VLINE
#define LeftCross       ACS_LTEE
#define RightCross      ACS_RTEE

using colorType = int;
using coord = unsigned;

