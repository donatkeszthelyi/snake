#ifndef BOARD_H
#define BOARD_H

#include "Food.h"
#include "Position.h"
#include "Snake.h"

class Board {
private:
    int width;
    int height;

public:
    Board(int width, int height);

    void render(const Snake &snake, const Food &food) const;

    bool isInside(Position position) const;
};

#endif
