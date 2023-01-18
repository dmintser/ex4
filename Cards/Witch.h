#ifndef WITCH_H
#define WITCH_H

#include "Card.h"

class Witch : public Card 
{
    public:
    Witch(CardType type);

    private:
    CardType m_class; 
}; 

#endif