#ifndef DRAGON_H
#define DRAGON_H

#include "Card.h"

class Dragon : public Card {
public:
  Dragon(CardType type, (25, 1000, 0, 0, 0, 0, 0));

private:
  CardType m_class;
};

#endif
