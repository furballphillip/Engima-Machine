#include "Reflector.h"

 Reflector::Reflector(const std::string& wiring)
    : left("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), right(wiring) {}

int Reflector::reflect(int signal) const
{
    char letter = left[signal];
    return right.find(letter); // Returns index of reflected letter
}
