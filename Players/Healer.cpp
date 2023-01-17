#include "Healer.h"

void Healer::heal(const int healPoint)
{
    Player::heal(2*healPoint);
}

std::ostream& Healer::operator<<(const Player& pl)
{
    printPlayerDetails()

}

