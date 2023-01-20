#include "Merchant.h"

Merchant::Merchant() :
    Card(CardType::Merchant, CardStats(0,0,0,5,10,1,1))
{}


/*std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os,"Merchant");
    printEndOfCardDetails(os);
    return os;
}*/

std::ostream& Merchant::printCard(std::ostream& os) const{
    printCardDetails(os, getName());
    printMonsterDetails(os, getForce(), getDamage(), getLoot(), false);
    printEndOfCardDetails(os);
    return os;
}