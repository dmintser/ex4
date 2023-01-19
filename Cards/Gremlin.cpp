#include "Gremlin.h"

Gremlin::Gremlin() :
    Card(CardType::Gremlin, CardStats(5,2,10,0,0,0,0))
{}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os,"Gremlin");
    printMonsterDetails(os,card.getForce(),card.getDamage(), card.getLoot(),false);
    printEndOfCardDetails(os);
}