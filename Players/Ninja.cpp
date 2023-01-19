#include "Ninja.h"

Ninja::Ninja(const char* name):
    Player(name)
{
    m_class="Ninja";
}

void Ninja::addCoins(const int coins)
{
    Player::addCoins(2*coins);
}

std::ostream& Ninja::operator<<(std::ostream& os)
{
    printPlayerDetails(os, m_name, m_class, m_level, m_force, m_hp, m_coins);
}