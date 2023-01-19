#include "Merchant.h"

Merchant::Merchant() :
    Card(CardType::Merchant, CardStats(0,0,0,5,10,1,1))
{}


std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os,"Merchant");
    printEndOfCardDetails(os);
}