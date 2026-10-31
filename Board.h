#ifndef BOARD_H
#define BOARD_H

#include "Food.h"
#include "Position.h"
#include "Snake.h"

/**
 * Manages the game board.
 *
 * Handles board dimensions, boundary checks, and rendering
 * of the snake and food.
 */
class Board {
private:
    int width;
    int height;

public:
    /**
     * Initializes the game board with the specified dimensions.
     *
     * @param width Width of the game board.
     * @param height Height of the game board.
     */
    Board(int width, int height);

    /**
     * Renders the game board, including the snake and food.
     *
     * @param snake Snake to display.
     * @param food Food to display.
     */
    void render(const Snake &snake, const Food &food) const;

    /**
     * Checks whether a position is inside the playable area.
     *
     * @param pos Position to check.
     * @return True if the position is inside the board boundaries.
     */
    bool isInside(Position position) const;
};

#endif
