#ifndef FOOD_H
#define FOOD_H

#include "Position.h"
#include "Snake.h"

/**
 * Manages the food position on the game board.
 *
 * Handles food placement while avoiding positions
 * occupied by the snake.
 */
class Food {
private:
    Position position;

public:
    /**
     * Creates food at a valid random position.
     *
     * @param boardWidth Width of the game board.
     * @param boardHeight Height of the game board.
     * @param snake Snake used to check occupied positions.
     */
    Food(int boardWidth, int boardHeight, const Snake &snake);

    /**
     * Returns the current food position.
     *
     * @return Current food coordinates.
     */
    Position getPosition() const;

    /**
     * Generates a new food position.
     *
     * Ensures the food does not overlap with the snake.
     *
     * @param boardWidth Width of the game board.
     * @param boardHeight Height of the game board.
     * @param snake Snake used to check occupied positions.
     */
    void spawn(int boardWidth, int boardHeight, const Snake &snake);
};

#endif
