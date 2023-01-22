#ifndef GREMLIN_H
#define GREMLIN_H

#include "Card.h"

class Gremlin : public Card 
{
    public:
    Gremlin();
    //friend std::ostream& operator<<(std::ostream& os, Gremlin &gremlin);
    virtual std::ostream& printCard(std::ostream& os) const;
}; 

#endif