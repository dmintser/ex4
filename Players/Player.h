#ifndef PLAYER_H
#define PLAYER_H

#include <cstring>
#include <string>

class Player {
  char *m_name;
  int m_level;
  int m_force;
  int m_maxHP;
  int m_hp;
  int m_coins;

public:
  Player(const char *name,const char *n_class, int maxHP = 100, int force = 5);
  Player(const Player &other);
  Player &operator=(const Player &other);
  ~Player();

  void printInfo() const;
  void levelUp();
  int getLevel() const;
  void buff(const int forcePoints);
  void heal(const int healPoint);
  void damage(const int damagePoints);
  bool isKnockedOut() const;
  void addCoins(const int coins);
  bool pay(const int coins);
  int getAttackStrength() const;
};

#endif // PLAYER_H
