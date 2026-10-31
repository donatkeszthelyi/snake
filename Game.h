#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Food.h"
#include "Input.h"
#include "Snake.h"

/**
 * Controls the overall game.
 *
 * Manages the game loop, input, updates, rendering,
 * score, and game state.
 */
class Game {
private:
    Board board;
    Snake snake;
    Food food;
    bool gameOver;
    int score;
    Input input;
    Direction nextDirection = Direction::up;

public:
    Game();

    /**
     * Updates the game state.
     *
     * Processes movement, food collection, and collision detection.
     */
    void update();

    /**
     * Displays the current game state.
     *
     * Renders the board and current score.
     */
    void render();

    /**
     * Starts and runs the game.
     *
     * Handles the start screen, game loop, and game-over screen.
     */
    void run();

    /**
     * Displays the game start screen.
     *
     * Shows the title, controls, and start prompt.
     */
    void showStartScreen();

    /**
     * Displays the game-over screen.
     *
     * Shows the final score.
     */
    void showGameOverScreen();
};

#endif
