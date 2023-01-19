#include "Dragon.h"

Dragon::Dragon() :
    Card(CardType::Dragon,CardStats(5,2,10,0,0,0,0))
{}

std::ostream& Dragon::operator<<(std::ostream& os)
{
  printCardDetails(os,"Dragon");
  printMonsterDetails(os, getForce(), getDamage(), getLoot(),true);
  printEndOfCardDetails(os);
}

