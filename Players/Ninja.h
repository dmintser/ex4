#ifndef NINJA_H
#define NINJA_H

#include "Player.h"

class Ninja : public Player
{
public:
    Ninja(const char* name);
    void addCoins(const int coins);
    std::ostream& operator<<(std::ostream& os);
};

#endif