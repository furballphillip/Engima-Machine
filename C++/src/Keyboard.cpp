#include "Keyboard.h"

int Keyboard::forward(char letter)
{
    // return letter - ASCII value 65
    return letter - 'A';
}

char Keyboard::backward(int signal)
{
    // return ASCII value 65 + singal (0-25)
    return 'A' + signal;
}
