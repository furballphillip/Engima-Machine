#include "Enigma.h"

Enigma::Enigma(const Reflector& re, const Rotor& r1, const Rotor& r2, const Rotor& r3,
           const Plugboard& pb, const Keyboard& kb)
           : re(re), r1(r1), r2(r2), r3(r3), kb(kb), pb(pb) {}

void Enigma::set_rings(const std::array<int, 3>& rings)
    {
        r1.set_ring(rings[0]);
        r1.set_ring(rings[1]);
        r1.set_ring(rings[2]);
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
        } else if (r2.get_left()[0] == r2.get_notch()) { // Double step anomaly of the Enigma
            r1.rotate();
            r2.rotate();
            r3.rotate();
        } else if (r2.get_left()[0] == r2.get_notch()) {
            r2.rotate();
            r3.rotate();
        } else {
            r3.rotate();
        }
        
        int signal;

        // Pass signal through Machine
        signal = kb.forward(letter);
        signal = pb.forward(letter);
        signal = r3.forward(letter);
        signal = r2.forward(letter);
        signal = r1.forward(letter);
        signal = re.reflect(letter);
        signal = r1.backward(letter);
        signal = r2.backward(letter);
        signal = r3.backward(letter);
        signal = pb.backward(letter);
        char encoded_letter = kb.backward(signal);

        return encoded_letter;
    }
