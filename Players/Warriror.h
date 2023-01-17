#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"

class Warrior : public Player
{
public:
    int getAttackStrength() const;
    std::ostream& operator<<(const Player& pl);
};


#endif