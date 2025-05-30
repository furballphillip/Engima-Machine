from keyboard import Keyboard # type: ignore
from plugboard import Plugboard
from rotor import Rotor
from reflector import Reflector
from enigma import Enigma

# Keyboard and plugboard
KB = Keyboard()
PB = Plugboard(["AB", "CD", "EF"])

# Historical enigma rotors and reflectors
I = Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", "Q")
II = Rotor("AJDKSIRUXBLHWTMCQGZNPYFVOE", "E")
III = Rotor("BDFHJLCPRTXVZNYEIWGAKMUSQO", "V")
IV = Rotor("ESOVPZJAYQUIRHXLNFTGKDCMWB", "J")
V = Rotor("VZBRGITYUPSDNHLXAWMJQOFECK", "Z")
A = Reflector("EJMZALYXVBWFCRQUONTSPIKHGD")
B = Reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT")
C = Reflector("FVPJIAOYEDRZXWGCTKUQSBNMHL")

# Define enigma machine
ENIGMA = Enigma(B,IV,II,I,PB,KB)

# Set the rings
ENIGMA.set_rings((5,26,2))

# Set message key
ENIGMA.set_key("CAT")

# Encipher message
message = "THISCOOLENIGMAMACHINE"
cipher_text = ""
for letter in message:
    cipher_text = cipher_text + ENIGMA.encipher(letter)
print(cipher_text)
