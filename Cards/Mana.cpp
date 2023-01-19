#include "Mana.h"

Mana::Mana() :
    Card(CardType::Mana, CardStats(0,0,0,0,0,10,0))
{}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os,"Mana");
    printEndOfCardDetails(os);

}