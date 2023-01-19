#include "Barfight.h"

Barfight::Barfight() : 
    Card(CardType::Barfight,CardStats(0,0,10,0,0,0,0))
{}

std::ostream& operator<<(std::ostream& os, const Card&)
{
    printCardDetails(os,"Barfight");
    printEndOfCardDetails(os);
}
