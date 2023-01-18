#ifndef MANA_H
#define MANA_H

#include "Card.h"

class Mana : public Card 
{
    public:
    Mana(CardType type);

    private:
    CardType m_class; 
}; 

#endif