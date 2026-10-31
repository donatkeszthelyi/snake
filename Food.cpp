#include "Food.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Food::Food(int boardWidth, int boardHeight, const Snake &snake) {
    srand(std::time(nullptr));
    spawn(boardWidth, boardHeight, snake);
}

Position Food::getPosition() const { return position; }

void Food::spawn(int boardWidth, int boardHeight, const Snake &snake) {
    bool overlapsSnake;

    do {
        position.x = 2 + (rand() % 9) * 2;
        position.y = 1 + rand() % (boardHeight - 2);

        overlapsSnake = false;

        for (const Position &segment : snake.getBody()) {
            if (position.x == segment.x && position.y == segment.y) {
                overlapsSnake = true;
                break;
            }
        }

    } while (overlapsSnake);
}
