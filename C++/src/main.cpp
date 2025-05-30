#include "Keyboard.h"
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"
#include "Enigma.h"
#include <iostream>
#include <string>

int main()
{
    Keyboard KB;
    Plugboard PB({ {'A', 'B'}, {'C', 'D'}, {'E', 'F'} });

    // Historical Enigma rotors and reflectors
    Rotor I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q');
    Rotor II("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E');
    Rotor III("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V');
    Rotor IV("ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J');
    Rotor V("VZBRGITYUPSDNHLXAWMJQOFECK", 'Z');

    Reflector A("EJMZALYXVBWFCRQUONTSPIKHGD");
    Reflector B("YRUHQSLDPXNGOKMIEBFZCWVJAT");
    Reflector C("FVPJIAOYEDRZXWGCTKUQSBNMHL");

    // Define Enigma machine
    Enigma enigma(B, IV, II, I, PB, KB);

    enigma.set_rings({4, 25, 1});
    enigma.set_key("CAT");

    std::string message = "THISCOOLENIGMAMACHINE";
    std::string cipher_text;

    for (char letter : message)
    {
        cipher_text += enigma.encipher(letter);
    }

    std::cout << cipher_text << "\n";

    return 0;
}
