#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"

class Merchant : public Card 
{
    public:
    Merchant(CardType type);

    private:
    CardType m_class; 
}; 

#endif