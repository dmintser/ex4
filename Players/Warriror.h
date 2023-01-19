#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
#include "../utilities.h"

class Warrior : public Player
{

public:
    Warrior(const char* name);
    int getAttackStrength() const;
    //friend std::ostream& operator<<(std::ostream& os, const Player& player);
    virtual std::ostream& printPlayer(std::ostream& os) const;
};


#endif