#ifndef ENIGMA_H
#define ENIGMA_H

#include "Reflector.h"
#include "Rotor.h"
#include "Plugboard.h"
#include "Keyboard.h"
#include <string>
#include <array>

class Enigma
{
private:
    Reflector re;
    Rotor r1;
    Rotor r2;
    Rotor r3;
    Plugboard pb;
    Keyboard kb;

public:
    Enigma(const Reflector& re, const Rotor& r1, const Rotor& r2, const Rotor& r3,
           const Plugboard& pb, const Keyboard& kb);

    void set_rings(const std::array<int, 3>& rings);
    void set_key(const std::string& key);
    char encipher(char letter);
};

#endif // ROTOR_H
