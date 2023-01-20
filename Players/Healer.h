#ifndef HEALER_H
#define HEALER_H

#include "Player.h"
#include "../utilities.h"

class Healer : public Player
{
public:
    Healer(const std::string name);
    void heal(const int healPoint);
    //friend std::ostream& operator<<(std::ostream& os, Healer &healer);
    virtual std::ostream& printPlayer(std::ostream& os) const;
};


#endif