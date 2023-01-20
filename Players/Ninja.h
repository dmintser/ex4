#ifndef NINJA_H
#define NINJA_H

#include "Player.h"
#include "../utilities.h"

class Ninja : public Player
{
public:
    Ninja(const std::string name);
    void addCoins(const int coins);
    //friend std::ostream& operator<<(std::ostream& os, Ninja &ninja);
    virtual std::ostream& printPlayer(std::ostream& os) const;
};

#endif