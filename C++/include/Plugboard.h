#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <string>
#include <vector>

class Plugboard
{
private:
    std::string left;
    std::string right;

public:
    Plugboard(const std::vector<std::pair<char, char>>& pairs);

    int forward(int signal) const;
    int backward(int signal) const;

};

#endif // PLUGBOARD_H
