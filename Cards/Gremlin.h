#ifndef GREMLIN_H
#define GREMLIN_H

#include "Card.h"

class Gremlin : public Card 
{
    public:
    Gremlin();
    friend std::ostream& operator<<(std::ostream& os, const Card&);
 
}; 

#endif