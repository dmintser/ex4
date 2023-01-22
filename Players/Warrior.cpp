#include "Warrior.h"

Warrior::Warrior(const std::string name):
    Player(name)
{
    m_class="Warrior";
}


int Warrior::getAttackStrength() const
{
    return (2*getForce()+getLevel());
}

/*std::ostream& operator<<(std::ostream& os, const Player& player)
{
    printPlayerDetails(os,player.m_name,player.m_class,player.m_level,player.m_force,player.m_hp,player.m_coins);
    return os;
}*/

std::ostream& Warrior::printPlayer(std::ostream& os) const{
    printPlayerDetails(os, m_name, m_class, m_level, m_force, m_hp, m_coins);
    return os;
}