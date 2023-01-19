#ifndef DRAGON_H
#define DRAGON_H

#include "Card.h"

class Dragon : public Card {
public:
  Dragon();
  std::ostream& operator<<(std::ostream& os) override;
};

#endif
