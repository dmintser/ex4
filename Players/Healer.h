#ifndef HEALER_H
#define HEALER_H

#include "Player.h"

class Healer : public Player
{
public:
    Healer(const char* name);
    void heal(const int healPoint);
    std::ostream& operator<<(std::ostream& os);
    

    
};


#endif