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

std::ostream& operator<<(std::ostream& os, Ninja &ninja)
{
    printPlayerDetails(os, ninja.m_name, ninja.m_class, ninja.m_level, ninja.m_force, ninja.m_hp, ninja.m_coins);
}