#ifndef DRAGON_H
#define DRAGON_H

#include "Card.h"

class Dragon : public Card {
public:
  Dragon();
  //friend std::ostream& operator<<(std::ostream& os, Dragon &dragon);
  virtual std::ostream& printCard(std::ostream& os) const;
};

#endif
