#include "Snake.h"
#include <iostream>

using namespace std;

Snake::Snake(Direction direction, Position startPosition) : direction(direction) {
    body.push_back(startPosition);

    Position bodyPosition = startPosition;
    bodyPosition.y++;

    body.push_back(bodyPosition);
}

Position Snake::getHead() const { return body.front(); }

Direction Snake::getDirection() const { return direction; }

const deque<Position> &Snake::getBody() const { return body; }

void Snake::move(bool grow) {
    Position newHead = body.front();

    switch (direction) {
    case Direction::up:
        newHead.y--;
        break;
    case Direction::down:
        newHead.y++;
        break;
    case Direction::left:
        newHead.x -= 2;
        break;

    case Direction::right:
        newHead.x += 2;
        break;
    }
    body.push_front(newHead);

    if (!grow) {
        body.pop_back();
    }
}

bool Snake::willCollideWithSelf(Position nextHead) const {
    for (size_t i = 1; i < body.size(); i++) {
        if (body[i].x == nextHead.x && body[i].y == nextHead.y) {
            return true;
        }
    }

    return false;
}

void Snake::changeDirection(Direction newDirection) {
    if (direction == Direction::up && newDirection == Direction::down)
        return;

    if (direction == Direction::down && newDirection == Direction::up)
        return;

    if (direction == Direction::left && newDirection == Direction::right)
        return;

    if (direction == Direction::right && newDirection == Direction::left)
        return;

    direction = newDirection;
}
