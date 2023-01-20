#include "Treasure.h"

Treasure::Treasure() :
    Card(CardType::Treasure, CardStats(0,10,0,0,0,0,0))
{}

/*std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os,"Treasure");
    printEndOfCardDetails(os);
    return os;
}*/

std::ostream& Treasure::printCard(std::ostream& os) const{
    printCardDetails(os, getName());
    printMonsterDetails(os, getForce(), getDamage(), getLoot(), false);
    printEndOfCardDetails(os);
    return os;
}