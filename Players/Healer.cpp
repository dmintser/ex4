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

std::ostream& Healer::operator<<(std::ostream& os)
{
    printPlayerDetails(os, m_name, m_class, m_level, m_force, m_hp, m_coins);
}

