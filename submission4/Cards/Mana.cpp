#include "Mana.h"

Mana::Mana() :
    Card(CardType::Mana, CardStats(0,0,0,0,0,10,0))
{}

/*std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os,"Mana");
    printEndOfCardDetails(os);
    return os;
}*/

std::ostream& Mana::printCard(std::ostream& os) const{
    printCardDetails(os, getName());
    printMonsterDetails(os, getForce(), getDamage(), getLoot(), false);
    printEndOfCardDetails(os);
    return os;
}