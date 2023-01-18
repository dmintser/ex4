#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card 
{
    public:
    Treasure(CardType type);

    private:
    CardType m_class; 
}; 

#endif