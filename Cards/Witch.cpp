#include "Witch.h"

Witch::Witch() :
    Card(CardType::Witch, CardStats(11,2,10,0,0,0,-1))
{}

/*std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os,"Witch");
    printMonsterDetails(os,card.getForce(),card.getDamage(), card.getLoot(),false);
    printEndOfCardDetails(os);
    return os;
}*/

std::ostream& Witch::printCard(std::ostream& os) const{
    printCardDetails(os, getName());
    printMonsterDetails(os, getForce(), getDamage(), getLoot(), false);
    printEndOfCardDetails(os);
    return os;
}