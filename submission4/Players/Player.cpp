#include "Player.h"
#include "../utilities.h"
#include <algorithm>

#define MAX_LEVEL 10



Player::Player(const std::string name, int maxHP, int force)
    : m_name(name), m_level(1), m_force(force),
      m_maxHP(maxHP), m_hp(maxHP), m_coins(10) 
{}
  
  


Player::Player(const Player &other)
    : m_name(new char[other.m_name.length() + 1]), m_level(other.m_level),
      m_force(other.m_force), m_maxHP(other.m_maxHP), m_hp(other.m_hp),
      m_coins(other.m_coins) {
        m_name = other.m_name;
  //strncpy(m_name, other.m_name, m_name.length() - 1);
  m_name[m_name.length()] = '\0'; // to be checked
}

Player &Player::operator=(const Player &other) {
  if (this == &other)
    return *this;
  //delete[] m_name;
  int other_len = other.m_name.length() + 1;
  m_name = new char[other_len];
  m_name[other_len - 1] = 0;

  for (int i = 0; i < other_len; i++)
    m_name[i] = other.m_name[i];

  m_level = other.m_level;
  m_force = other.m_force;
  m_maxHP = other.m_maxHP;
  m_hp = other.m_hp;
  m_coins = other.m_coins;

  return *this;
}





// Player::Player(const std::string name, int maxHP, int force)
//     : m_name(new char[strlen(name) + 1]), m_level(1), m_force(force),
//       m_maxHP(maxHP), m_hp(maxHP), m_coins(0) {
//   int nameLen = strlen(name);
//   for (int i = 0; i < nameLen; i++) {
//     m_name[i] = name[i];
//   }
//   m_name[strlen(name)] = '\0';
// }

// Player::Player(const Player &other)
//     : m_name(new char[strlen(other.m_name) + 1]), m_level(other.m_level),
//       m_force(other.m_force), m_maxHP(other.m_maxHP), m_hp(other.m_hp),
//       m_coins(other.m_coins) {
//   strncpy(m_name, other.m_name, strlen(m_name) - 1);
//   m_name[strlen(m_name)] = '\0'; // to be checked
// }

// Player &Player::operator=(const Player &other) {
//   if (this == &other)
//     return *this;
//   delete[] m_name;
//   int other_len = strlen(other.m_name) + 1;
//   m_name = new char[other_len];
//   m_name[other_len - 1] = 0;

//   for (int i = 0; i < other_len; i++)
//     m_name[i] = other.m_name[i];

//   m_level = other.m_level;
//   m_force = other.m_force;
//   m_maxHP = other.m_maxHP;
//   m_hp = other.m_hp;
//   m_coins = other.m_coins;

//   return *this;
// }

//Player::~Player() { delete[] m_name; }
/*
void Player::printInfo() const {
  printPlayerInfo(m_name, m_level, m_force, m_hp, m_coins);
  
}
*/

void Player::levelUp() {
  void levelUp();
  if (m_level == MAX_LEVEL) {
    return;
  }
  m_level += 1;
}

int Player::getCoins() const{
  return m_coins;
}
std::string Player::getName() const
{
  return m_name;
}

int Player::getForce() const
{
  return m_force;
}

std::string Player::getClass() const
{
  return m_class;
}

int Player::getLevel() const { return m_level; }

int Player::getHP() const
{
  return m_hp;
}
void Player::buff(const int forcePoints) { m_force += forcePoints; }

void Player::heal(const int healPoint) {
  if (healPoint < 0)
    return;
  else if (m_hp + healPoint >= m_maxHP) {
    m_hp = m_maxHP;
    return;
  } else
    m_hp += healPoint;
  return;
}

void Player::damage(const int damagePoints) {
  if (damagePoints < 0) {
    return;
  }
  if (m_hp < damagePoints) {
    m_hp = 0;
    return;
  }
  m_hp -= damagePoints;
}

int Player::doneGame() const 
{ 
  if(m_level>=10)
  {
    return 1;

  }
  else if(m_hp <= 0)
  {
    return 2; 
  }
  else
  {
    return 0;
  }
}

void Player::addCoins(const int coinsEarned) { m_coins += coinsEarned; }

bool Player::pay(const int coins) {
  if (m_coins - coins >= 0) {
    m_coins -= coins;
    return true;
  }
  return false;
}

int Player::getAttackStrength() const {
  return m_force + m_level; // Attack Strength = force + level
}

std::ostream& operator<<(std::ostream &os, const Player &player)
{
  //printPlayerDetails(os, player.getName(), player.getClass(), player.getLevel(), player.getAttackStrength(),
  //player.getHP(), player.getCoins());
  player.printPlayer(os);
  return os;
}
