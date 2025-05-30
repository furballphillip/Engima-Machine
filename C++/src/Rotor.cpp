#include "Rotor.h"
#include <iostream>

Rotor::Rotor(const std::string& wiring, char notch)
    : left("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), right(wiring), notch(notch) {}

int Rotor::forward(int signal) const
{
    char letter = right[signal];
    return left.find(letter);
}

int Rotor::backward(int signal) const
{
    char letter = left[signal];
    return left.find(letter);
}

void Rotor::rotate(int n, bool forward)
{
    for (int i = 0; i < n; ++i)
    {
        if (forward)
        {
            left = left.substr(1) + left[0];
            right = right.substr(1) + right[0];
        }
        else
        {
            left = left.back() + left[0, 25];
            right = right.back() + right[0, 25];
        }
    }
}

void Rotor::rotate_to_letter(char letter)
{
    int n = left.find(letter);
    rotate(n);
}

void Rotor::set_ring(int n)
{
    // Rotate rotor backwards
    rotate(n - 1, false);

    // Adjust turnover notch in relation to the wiring
    int notch_index = std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ").find(notch);
    notch = std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ")[(notch_index - n + 26) % 26];
}

void Rotor::show() const
{
    std::cout << left << "\n" << right << "\n\n";
}
