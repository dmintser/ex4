#ifndef NINJA_H
#define NINJA_H

#include "Player.h"

class Ninja : public Player
{
public:
    Ninja(const char* name);
    void addCoins(const int coins);
    friend std::ostream& operator<<(std::ostream& os, const Player&);
};

#endif