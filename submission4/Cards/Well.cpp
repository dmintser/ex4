#include "Well.h"

Well::Well() :
    Card(CardType::Well, CardStats(0,0,10,0,0,0,0))
{}

/*std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os,"Well");
    printEndOfCardDetails(os);
    return os;
}*/

std::ostream& Well::printCard(std::ostream& os) const{
    printCardDetails(os, getName());
    printMonsterDetails(os, getForce(), getDamage(), getLoot(), false);
    printEndOfCardDetails(os);
    return os;
}