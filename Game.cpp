#include "Game.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

Game::Game()
    : board(21, 11), snake(Direction::up, {10, 5}), food(21, 11, snake), gameOver(false), score(0),
      nextDirection(Direction::up) {}

void Game::update() {
    Position nextHead = snake.getHead();

    switch (snake.getDirection()) { // Check next move
    case Direction::up:
        nextHead.y--;
        break;
    case Direction::down:
        nextHead.y++;
        break;
    case Direction::left:
        nextHead.x -= 2;
        break;

    case Direction::right:
        nextHead.x += 2;
        break;
    }

    if (!board.isInside(nextHead)) {
        gameOver = true;
        return;
    }

    if (snake.willCollideWithSelf(nextHead)) {
        gameOver = true;
        return;
    }

    bool ateFood = nextHead.x == food.getPosition().x && nextHead.y == food.getPosition().y;

    snake.move(ateFood);

    if (ateFood) {
        score += 10;
        food.spawn(21, 11, snake);
    }
}

void Game::render() {
    board.render(snake, food);
    cout << CYAN << "\n\n";
    cout << "                         SCORE: " << setw(3) << setfill('0') << score << RESET << "\n";
}

void Game::run() {
    showStartScreen();
    input.waitForKey();
    using clock = chrono::steady_clock;

    const auto moveInterval = chrono::milliseconds(500);
    auto nextMove = clock::now() + moveInterval;

    cout << "\033[2J\033[H";
    cout << CYAN << R"(
          ███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗
          ██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝
          ███████╗██╔██╗ ██║███████║█████╔╝ █████╗
          ╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝
          ███████║██║ ╚████║██║  ██║██║  ██╗███████╗
          ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝

)" << RESET
         << endl;

    render();

    while (!gameOver) {
        Direction newDirection;
        if (input.readDirection(newDirection)) {
            bool invalidDirection =
                newDirection == snake.getDirection() ||
                (snake.getDirection() == Direction::up && newDirection == Direction::down) ||
                (snake.getDirection() == Direction::down && newDirection == Direction::up) ||
                (snake.getDirection() == Direction::left && newDirection == Direction::right) ||
                (snake.getDirection() == Direction::right && newDirection == Direction::left);

            if (!invalidDirection) {
                nextDirection = newDirection;
            }
        }

        if (clock::now() >= nextMove) {
            snake.changeDirection(nextDirection);
            update();

            nextMove += moveInterval;

            if (gameOver) {
                break;
            }

            std::cout << "\033[H";
            cout << CYAN << R"(
          ███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗
          ██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝
          ███████╗██╔██╗ ██║███████║█████╔╝ █████╗
          ╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝
          ███████║██║ ╚████║██║  ██║██║  ██╗███████╗
          ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝

)" << RESET << endl;
            render();
        }

        this_thread::sleep_for(chrono::milliseconds(5));
    }
    showGameOverScreen();
}

void Game::showStartScreen() {
    cout << "\033[2J\033[H";

    cout << CYAN << R"(
          ███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗
          ██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝
          ███████╗██╔██╗ ██║███████║█████╔╝ █████╗
          ╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝
          ███████║██║ ╚████║██║  ██║██║  ██╗███████╗
          ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝

               ━━━ THE CLASSIC ARCADE GAME ━━━      

                    
            Use the arrow keys to control the snake.

                  Press any key to start...

    )";
    cout << RESET;

    cout.flush();
}

void Game::showGameOverScreen() {
    cout << "\033[2J\033[H";

    cout << CYAN << R"(
          ███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗
          ██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝
          ███████╗██╔██╗ ██║███████║█████╔╝ █████╗
          ╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝
          ███████║██║ ╚████║██║  ██║██║  ██╗███████╗
          ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝

              ╔══════════════════════════════╗
              ║                              ║
              ║          GAME OVER           ║
              ║                              ║
              ╚══════════════════════════════╝

                      ★ FINAL SCORE ★

    )";

    cout << "                        " << setw(3) << setfill('0') << score << "\n\n";

    cout << R"(
                    THANKS FOR PLAYING!)";
    cout << RESET << endl << endl;
    cout.flush();
}
