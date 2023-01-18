#ifndef WELL_H
#define WELL_H

#include "Card.h"

class Well : public Card 
{
    public:
    Well(CardType type);

    private:
    CardType m_class; 
}; 

#endif