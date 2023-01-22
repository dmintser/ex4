#ifndef WELL_H
#define WELL_H

#include "Card.h"

class Well : public Card 
{
    public:
    Well();
    //friend std::ostream& operator<<(std::ostream& os, const Card& card);
    virtual std::ostream& printCard(std::ostream& os) const;
}; 

#endif