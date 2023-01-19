#ifndef PLAYER_H
#define PLAYER_H

#include <cstring>
#include <string>
#include <iostream>
#include "../utilities.h"

class Player {
protected:
  char* m_name;
  char *m_class;
  int m_level;
  int m_force;
  int m_maxHP;
  int m_hp;
  int m_coins;
  

public:
  Player(const char *name, int maxHP = 100, int force = 5);
  Player(const Player &other);
  Player &operator=(const Player &other);
  virtual ~Player()=default;

  void printInfo() const;
  void levelUp();
  int getCoins() const;
  std::string getName() const; 
  std::string getClass() const;
  int getLevel() const;
  int getHP() const;
  void buff(const int forcePoints);
  virtual void heal(const int healPoint);
  void damage(const int damagePoints);
  int doneGame() const;
  virtual void addCoins(const int coins);
  bool pay(const int coins);
  virtual int getAttackStrength() const;
  virtual std::ostream& operator<<(std::ostream& os);
};



#endif // PLAYER_H
