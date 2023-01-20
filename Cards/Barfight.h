#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

class Barfight : public Card 
{
    public:
    Barfight();
    //friend std::ostream& operator<<(std::ostream& os, const Card&);
    virtual std::ostream& printCard(std::ostream& os) const;
}; 

#endif