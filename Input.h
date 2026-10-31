#ifndef INPUT_H
#define INPUT_H

#include "Snake.h"

/**
 * Handles keyboard input from the terminal.
 *
 * Reads arrow-key presses and manages terminal input settings.
 */
class Input {
public:
    /**
     * Initializes terminal input settings.
     *
     * Configures the terminal for non-blocking key input.
     */
    Input();

    /**
     * Restores the original terminal settings.
     */
    ~Input();

    /**
     * Attempts to read an arrow-key direction.
     *
     * @param direction Variable that receives the detected direction.
     * @return True if a valid direction key was detected.
     */
    bool readDirection(Direction &direction);

    /**
     * Waits until a key is pressed.
     */
    void waitForKey();

private:
    bool terminalConfigured;
};

#endif
