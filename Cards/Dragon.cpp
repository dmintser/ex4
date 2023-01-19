#include "Dragon.h"

Dragon::Dragon() :
    Card(CardType::Dragon,CardStats(5,2,10,0,0,0,0))
{}

  std::ostream& operator<<(std::ostream& os, const Card& card)
  {
    printCardDetails(os,"Dragon");
    printMonsterDetails(os,card.getForce(),card.getDamage(), card.getLoot(),true);
    printEndOfCardDetails(os);
  }

