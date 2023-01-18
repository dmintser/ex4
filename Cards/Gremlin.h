#ifndef GREMLIN_H
#define GREMLIN_H

#include "Card.h"

class Gremlin : public Card 
{
    public:
    Gremlin(CardType type);

    private:
    CardType m_class; 
}; 

#endif