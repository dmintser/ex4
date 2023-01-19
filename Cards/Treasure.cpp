#include "Treasure.h"

Treasure::Treasure() :
    Card(CardType::Treasure, CardStats(0,10,0,0,0,0,0))
{}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os,"Treasure");
    printEndOfCardDetails(os);
    return os;
}