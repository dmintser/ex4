#include "Warriror.h"

Warrior::Warrior(const char* name):
    Player(name)
{
    m_class="Warrior";
}


int Warrior::getAttackStrength() const
{
    return (this->getAttackStrength()+this->getLevel());
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    printPlayerDetails(os,player.m_name,player.m_class,player.m_level,player.m_force,player.m_hp,player.m_coins);
    return os;
}
