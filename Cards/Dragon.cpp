#include "Dragon.h"

Dragon::Dragon() :
    Card(CardType::Dragon,CardStats(25,2,10,0,0,0,0))
{}

/*std::ostream& operator<<(std::ostream& os, Dragon &dragon)
{
  printCardDetails(os,"Dragon");
  printMonsterDetails(os, dragon.getForce(), dragon.getDamage(), dragon.getLoot(),true);
  printEndOfCardDetails(os);
  return os;
}*/

std::ostream& Dragon::printCard(std::ostream& os) const{
    printCardDetails(os, getName());
    printMonsterDetails(os, getForce(), getDamage(), getLoot(), false);
    printEndOfCardDetails(os);
    return os;
}

