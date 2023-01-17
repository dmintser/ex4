#ifndef NINJA_H
#define NINJA_H

#include "Player.h"

class Ninja : public Player
{
public:
    void addCoins(const int coins);
    std::ostream& operator<<(const Player& pl);
};

#endif