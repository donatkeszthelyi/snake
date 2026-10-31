#include "Board.h"
#include <iostream>

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

Board::Board(int width, int height) : width(width), height(height) {}

void Board::render(const Snake &snake, const Food &food) const {
    const auto &body = snake.getBody();
    Position foodPosition = food.getPosition();

    for (int y = 0; y < height; y++) {
        cout << "                    ";
        for (int x = 0; x < width; x++) {
            if (x == 0 && y == 0) {
                cout << "╔"; // Top left
            } else if (x == width - 1 && y == 0) {
                cout << "╗"; // Top right
            } else if (x == 0 && y == height - 1) {
                cout << "╚"; // Bottom left
            } else if (x == width - 1 && y == height - 1) {
                cout << "╝"; // Bottom right
            } else if (y == 0) {
                cout << "═"; // Top
            } else if (y == height - 1) {
                cout << "═"; // Bottom
            } else if (x == 0 || x == width - 1) {
                cout << "║"; // Sides
            } else if (x == snake.getHead().x && y == snake.getHead().y) {
                cout << CYAN << "●" << RESET; // Snake head
            } else {
                bool isSnakeBody = false;

                for (const Position &segment : body) {
                    if (segment.x == x && segment.y == y) {
                        isSnakeBody = true;
                        break;
                    }
                }

                if (isSnakeBody) {
                    cout << CYAN << "○" << RESET; // Snake body
                } else if (x == foodPosition.x && y == foodPosition.y) {
                    cout << GREEN << "◆" << RESET; // Food
                } else {
                    cout << " "; // Empty
                }
            }
        }
        cout << RESET << endl;
    }
}

bool Board::isInside(Position pos) const {
    return pos.x > 0 && pos.x < width - 1 && pos.y > 0 && pos.y < height - 1;
}
