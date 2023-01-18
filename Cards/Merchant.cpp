#include "Merchant.h"

Merchant::Card(CardType type) :
    Card((0,0,0,5,10,1,1)), m_class(type);
{}
