#include "Enigma.h"
#include <iostream>

Enigma::Enigma(const Reflector& re, const Rotor& r1, const Rotor& r2, const Rotor& r3,
           const Plugboard& pb, const Keyboard& kb)
           : re(re), r1(r1), r2(r2), r3(r3), kb(kb), pb(pb) {}

void Enigma::set_rings(const std::array<int, 3>& rings)
{
    int n1 = rings[0];
    int n2 = rings[1];
    int n3 = rings[2];

    if (n1 < 0 || n1 >= 26 || n2 < 0 || n2 >= 26 || n3 < 0 || n3 >= 26)
    {
        std::cerr << "Invalid ring setting: must be in range [0, 25]\n";
        return;
    }

    r1.set_ring(n1);
    r2.set_ring(n2);
    r3.set_ring(n3);
}

    void Enigma::set_key(const std::string& key)
    {
        if (key.size() < 3) return; // Simple validation
        r1.rotate_to_letter(key[0]);
        r2.rotate_to_letter(key[1]);
        r3.rotate_to_letter(key[2]);
    }

char Enigma::encipher(char letter)
{
    if (r2.get_left()[0] == r2.get_notch() && r3.get_left()[0] == r3.get_notch()) {
        r1.rotate();
        r2.rotate();
        r3.rotate();
    }
    else if (r2.get_left()[0] == r2.get_notch()) { // Double step anomaly of the Enigma
        r1.rotate();
        r2.rotate();
        r3.rotate();
    }
    else if (r3.get_left()[0] == r3.get_notch()) {
        r2.rotate();
        r3.rotate();
    }
    else {
        r3.rotate();
    }

	int signal = kb.forward(letter);

    // Pass signal through Machine
    signal = pb.forward(signal);
    signal = r3.forward(signal);
    signal = r2.forward(signal);
    signal = r1.forward(signal);
    signal = re.reflect(signal);
    signal = r1.backward(signal);
    signal = r2.backward(signal);
    signal = r3.backward(signal);
    signal = pb.backward(signal);
    char encoded_letter = kb.backward(signal);

    return encoded_letter;
}