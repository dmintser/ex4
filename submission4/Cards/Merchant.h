#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"

class Merchant : public Card 
{
    public:
    Merchant();
    //friend std::ostream& operator<<(std::ostream& os, const Card& card);
    virtual std::ostream& printCard(std::ostream& os) const;
}; 

#endif