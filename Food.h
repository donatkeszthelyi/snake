#ifndef FOOD_H
#define FOOD_H

#include "Position.h"
#include "Snake.h"

class Food {
private:
    Position position;

public:
    Food(int boardWidth, int boardHeight, const Snake &snake);

    Position getPosition() const;
    void spawn(int boardWidth, int boardHeight, const Snake &snake);
};

#endif
