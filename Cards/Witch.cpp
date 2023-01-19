#include "Witch.h"

Witch::Witch() :
    Card(CardType::Witch, CardStats(11,2,10,0,0,0,-1))
{}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os,"Witch");
    printMonsterDetails(os,card.getForce(),card.getDamage(), card.getLoot(),false);
    printEndOfCardDetails(os);
}