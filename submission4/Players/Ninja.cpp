#include "Ninja.h"

Ninja::Ninja(const std::string name):
    Player(name)
{
    m_class="Ninja";
}

void Ninja::addCoins(const int coins)
{
    Player::addCoins(2*coins);
}

/*std::ostream& operator<<(std::ostream& os, Ninja &ninja)
{
    printPlayerDetails(os, ninja.m_name, ninja.m_class, ninja.m_level, ninja.m_force, ninja.m_hp, ninja.m_coins);
    return os;
}*/

std::ostream& Ninja::printPlayer(std::ostream& os) const{
    printPlayerDetails(os, m_name, m_class, m_level, m_force, m_hp, m_coins);
    return os;
}