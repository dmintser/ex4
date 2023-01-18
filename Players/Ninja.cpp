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

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    printPlayerDetails(os,player.m_name,player.m_class,player.m_level,player.m_force,player.m_hp,player.m_coins);
}