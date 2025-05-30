#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>

class Reflector
{
private:
    std::string left;
    std::string right;

public:
    Reflector(const std::string& wiring);

    // Reflects a signal (int 0-25) to a different int
    int reflect(int signal) const;
};

#endif // REFLECTOR_H
