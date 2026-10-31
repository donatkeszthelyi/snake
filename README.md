# Snake

A command-line implementation of the classic Snake game written in C++.

## Features

- Terminal-based gameplay.
- Real-time movement using arrow-key controls.
- Food spawning at valid positions.
- Snake growth when food is collected.
- Wall and self-collision detection.
- Score tracking.
- Start and game-over screens.

## Requirements

- A C++ compiler supporting C++11 or later.
- GNU Make.
- A terminal that supports ANSI escape sequences and arrow-key input.

## Build

Clone the repository and navigate to the project directory.

Build the executable using:

```bash
make
```

This compiles the source files and produces an executable named `game`.

## Run

Start the game with:

```bash
./game
```

Press any key when prompted to start the game.

## How to Play

Control the snake using the arrow keys:

- `↑` — Move up.
- `↓` — Move down.
- `←` — Move left.
- `→` — Move right.

Collect food to grow the snake and increase your score.

The game ends if the snake hits a wall or collides with itself. Each piece of food collected awards 10 points.

## Project Structure

```text
.
├── main.cpp
├── Position.h
├── Board.h
├── Board.cpp
├── Snake.h
├── Snake.cpp
├── Food.h
├── Food.cpp
├── Game.h
├── Game.cpp
├── Input.h
├── Input.cpp
├── Makefile
└── .gitignore
```

- `main.cpp` — Program entry point.
- `Position.h` — Defines the position structure used by the game.
- `Board.h / Board.cpp` — Handles board dimensions, boundaries, and rendering.
- `Snake.h / Snake.cpp` — Implements snake movement, direction changes, and collision detection.
- `Food.h / Food.cpp` — Handles food positioning and spawning.
- `Game.h / Game.cpp` — Manages the game loop, updates, score, and game screens.
- `Input.h / Input.cpp` — Handles keyboard input.
- `Makefile` — Defines the build rules.
- `.gitignore` — Specifies files excluded from version control.

## Current Limitations

- The game does not currently support restarting after a game over.
- Scores are not saved between sessions.
- The game is designed for terminal environments that support the required keyboard input and display features.

## License

No license has been specified for this project.
