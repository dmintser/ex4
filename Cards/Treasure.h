#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card 
{
    public:
    Treasure();
    //friend std::ostream& operator<<(std::ostream& os, const Card& card);
    virtual std::ostream& printCard(std::ostream& os) const;
}; 

#endif