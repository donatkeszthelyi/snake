#include "Input.h"

#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

namespace {
termios originalTerminal;

bool readByte(char &c, int timeoutMs) {
    fd_set set;
    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);

    timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = timeoutMs * 1000;

    int result = select(STDIN_FILENO + 1, &set, nullptr, nullptr, &timeout);

    if (result <= 0) {
        return false;
    }

    return read(STDIN_FILENO, &c, 1) == 1;
}
} // namespace

Input::Input() : terminalConfigured(false) {
    if (tcgetattr(STDIN_FILENO, &originalTerminal) == 0) {
        termios newTerminal = originalTerminal;

        newTerminal.c_lflag &= ~(ICANON | ECHO);
        newTerminal.c_cc[VMIN] = 0;
        newTerminal.c_cc[VTIME] = 0;

        if (tcsetattr(STDIN_FILENO, TCSANOW, &newTerminal) == 0) {
            terminalConfigured = true;
        }
    }
}

Input::~Input() {
    if (terminalConfigured) {
        tcsetattr(STDIN_FILENO, TCSANOW, &originalTerminal);
    }
}

bool Input::readDirection(Direction &direction) {
    char c;

    if (!readByte(c, 0)) {
        return false;
    }

    if (c != '\033') {
        return false;
    }

    char sequence;
    char key;

    if (!readByte(sequence, 20)) {
        return false;
    }

    if (!readByte(key, 20)) {
        return false;
    }

    if (sequence != '[' && sequence != 'O') {
        return false;
    }

    switch (key) {
    case 'A':
        direction = Direction::up;
        return true;

    case 'B':
        direction = Direction::down;
        return true;

    case 'C':
        direction = Direction::right;
        return true;

    case 'D':
        direction = Direction::left;
        return true;
    }

    return false;
}

void Input::waitForKey() {
    char c;

    while (!readByte(c, 100)) {
        // Wait until a key is pressed.
    }
}
