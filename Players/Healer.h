#ifndef HEALER_H
#define HEALER_H

#include "Player.h"

class Healer : public Player
{
public:
    void heal(const int healPoint);
    std::ostream& operator<<(const Player& pl);
    
};


#endif