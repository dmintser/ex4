#include "Healer.h"

Healer::Healer(const char *name):
    Player(name)
{
    m_class="Healer";
}

void Healer::heal(const int healPoint)
{
    Player::heal(2*healPoint);
}

/*std::ostream& operator<<(std::ostream& os, Healer &healer)
{
    printPlayerDetails(os, healer.m_name, healer.m_class, healer.m_level, healer.m_force, healer.m_hp, healer.m_coins);
    return os;
}*/

std::ostream& Healer::printPlayer(std::ostream& os) const{
    printPlayerDetails(os, m_name, m_class, m_level, m_force, m_hp, m_coins);
    return os;
}