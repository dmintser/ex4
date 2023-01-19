#include "Gremlin.h"

Gremlin::Gremlin() :
    Card(CardType::Gremlin, CardStats(5,2,10,0,0,0,0))
{}

std::ostream& operator<<(std::ostream& os, Gremlin &gremlin)
{
    printCardDetails(os,"Gremlin");
    printMonsterDetails(os, gremlin.getForce(), gremlin.getDamage(), gremlin.getLoot(), false);
    printEndOfCardDetails(os);
}