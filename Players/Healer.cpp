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

std::ostream& operator<<(std::ostream& os, Healer &healer)
{
    printPlayerDetails(os, healer.m_name, healer.m_class, healer.m_level, healer.m_force, healer.m_hp, healer.m_coins);
    return os;
}

