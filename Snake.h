#ifndef SNAKE_H
#define SNAKE_H

#include "Position.h"
#include <deque>

using namespace std;

/**
 * Represents the four possible movement directions.
 */
enum class Direction { left, right, up, down };

/**
 * Represents the snake.
 *
 * Manages the snake's body, movement, direction,
 * and self-collision detection.
 */
class Snake {
private:
    Direction direction;
    deque<Position> body;

public:
    /**
     * Creates a snake at the specified starting position.
     *
     * @param direction Initial movement direction.
     * @param startPosition Initial head position.
     */
    Snake(Direction direction = Direction::up, Position position = {10, 5});

    const std::deque<Position> &getBody() const;
    Position getHead() const;
    Direction getDirection() const;

    /**
     * Moves the snake one step in its current direction.
     *
     * @param grow Determines whether the snake grows instead of
     *             removing its tail.
     */
    void move(bool grow = false);

    /**
     * Checks whether the next head position overlaps the body.
     *
     * @param nextHead Position the head is about to occupy.
     * @return True if a collision will occur.
     */
    bool willCollideWithSelf(Position nextHead) const;

    /**
     * Changes the snake's movement direction.
     *
     * Opposite directions are ignored.
     *
     * @param newDirection Requested movement direction.
     */
    void changeDirection(Direction newDirection);
};

#endif
