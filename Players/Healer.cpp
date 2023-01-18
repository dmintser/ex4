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

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    printPlayerDetails(os,player.m_name,player.m_class,player.m_level,player.m_force,player.m_hp,player.m_coins);
}

