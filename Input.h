#ifndef INPUT_H
#define INPUT_H

#include "Snake.h"

class Input {
public:
    Input();
    ~Input();

    bool readDirection(Direction &direction);
    void waitForKey();

private:
    bool terminalConfigured;
};

#endif
