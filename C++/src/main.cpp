#include "Rotor.h"
#include <iostream>

int main() {
    // Create a rotor with Rotor I wiring and notch at 'Q'
    Rotor rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q');

    std::cout << "Initial Rotor:\n";
    rotor.show();

    // Test forward mapping (A -> ?)
    int input = 0; // 'A'
    int output = rotor.forward(input);
    std::cout << "Forward(A): " << output << " (" << char('A' + output) << ")\n";

    // Test backward mapping (output -> original input)
    int back = rotor.backward(output);
    std::cout << "Backward(" << output << "): " << back << " (" << char('A' + back) << ")\n";

    // Test rotation
    rotor.rotate();
    std::cout << "\nAfter 1 rotation:\n";
    rotor.show();

    // Rotate to letter 'D'
    rotor.rotate_to_letter('D');
    std::cout << "\nAfter rotating to letter D:\n";
    rotor.show();

    // Test setRing
    rotor.set_ring(2);
    std::cout << "\nAfter setting ring to position 2:\n";
    rotor.show();

    return 0;
}
