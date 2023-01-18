#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

class Barfight : public Card 
{
    public:
    Barfight(CardType type);

    private:
    CardType m_class; 
}; 

#endif