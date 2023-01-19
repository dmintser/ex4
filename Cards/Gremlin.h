#ifndef GREMLIN_H
#define GREMLIN_H

#include "Card.h"

class Gremlin : public Card 
{
    public:
    Gremlin();
    std::ostream& operator<<(std::ostream& os) override;
 
}; 

#endif