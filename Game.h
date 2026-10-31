#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Food.h"
#include "Input.h"
#include "Snake.h"

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
    void update();
    void render();
    void run();
    void showStartScreen();
    void showGameOverScreen();
};

#endif
