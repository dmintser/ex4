#ifndef WITCH_H
#define WITCH_H

#include "Card.h"

class Witch : public Card 
{
    public:
    Witch();
    //friend std::ostream& operator<<(std::ostream& os, const Card&);
    virtual std::ostream& printCard(std::ostream& os) const; 
}; 

#endif