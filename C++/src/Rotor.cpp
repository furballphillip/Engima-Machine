#include "Rotor.h"
#include <iostream>

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

Rotor::Rotor(const std::string& wiring, char notch)
    : left(alphabet), right(wiring), notch(notch) {
}

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
    const int size = left.size();
    n = n % size;

    for (int i = 0; i < n; ++i)
    {
        if (forward)
        {
			// Rotate both strings left
            left = left.substr(1) + left[0];
            right = right.substr(1) + right[0];
        }
        else
        {
            // Rotate both strings right
            left = left.back() + left.substr(0, size - 1);
            right = right.back() + right.substr(0, size - 1);
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
    int notch_index = std::string(alphabet).find(notch);
    if (notch_index == std::string::npos) 
    {
        std::cerr << "Invalid notch character: " << notch << "\n";
        return;
    }

    notch = alphabet[(notch_index - n + 26) % 26];

    std::cout << "New notch position: " << notch << "\n";
}

void Rotor::show() const
{
    std::cout << "Left:  " << left << std::endl;
    std::cout << "Right: " << right << std::endl;
}

const std::string& Rotor::get_left() const
{
    return left;
}

char Rotor::get_notch() const
{
    return notch;
}
