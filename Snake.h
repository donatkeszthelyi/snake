#ifndef SNAKE_H
#define SNAKE_H

#include "Position.h"
#include <deque>

using namespace std;

enum class Direction { left, right, up, down };

class Snake {
private:
    Direction direction;
    deque<Position> body;

public:
    Snake(Direction direction = Direction::up, Position position = {10, 5});

    const std::deque<Position> &getBody() const;
    Position getHead() const;
    Direction getDirection() const;

    void move(bool grow = false);
    bool willCollideWithSelf(Position nextHead) const;
    void changeDirection(Direction newDirection);
};

#endif
