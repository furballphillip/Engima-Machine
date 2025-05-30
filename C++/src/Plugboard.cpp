#include "Plugboard.h"

Plugboard::Plugboard(const std::vector<std::pair<char, char>>& pairs)
    : left("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), right("ABCDEFGHIJKLMNOPQRSTUVWXYZ") 
{
    for (const auto& pair: pairs)
    {
        char A = pair.first;
        char B = pair.second;

        size_t pos_A = left.find(A);
        size_t pos_B = right.find(B);

        if (pos_A != std::string::npos && pos_B != std::string::npos)
        {
            // Swap A and B in left
            left[pos_A] = B;
            left[pos_B] = A;
        }
    }
}

int Plugboard::forward(int signal) const
{
    char letter = right[signal];
    return left.find(letter);
}

int Plugboard::backward(int signal) const
{
    char letter = left[signal];
    return left.find(letter);
}
