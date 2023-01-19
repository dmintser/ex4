#include "Gremlin.h"

Gremlin::Gremlin() :
    Card(CardType::Gremlin, CardStats(5,2,10,0,0,0,0))
{}

std::ostream& Gremlin::operator<<(std::ostream& os)
{
    printCardDetails(os,"Gremlin");
    printMonsterDetails(os,getForce(), getDamage(), getLoot(), false);
    printEndOfCardDetails(os);
}