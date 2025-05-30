#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor
{
private:
    std::string left;
    std::string right;
    char notch;

public:
    Rotor(const std::string& wiring, char notch);

    int forward(int signal) const;
    int backward(int signal) const;

    void rotate(int n = 1, bool forward = true);
    void rotate_to_letter(char letter);
    void set_ring(int n);

    void show() const;
};

#endif // ROTOR_H
