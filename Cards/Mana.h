#ifndef MANA_H
#define MANA_H

#include "Card.h"

class Mana : public Card 
{
    public:
    Mana();
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
}; 

#endif