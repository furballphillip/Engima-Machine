#ifndef KEYBOARD_H
#define KEYBOARD_H

class Keyboard
{
public:
    // Converts a letter (A-Z) into a signal (0-25)
    int forward(char letter);

    // Converts a signal (0-25) back into a letter (A-Z)
    char backward(int signal);
};

#endif // KEYBOARD_H