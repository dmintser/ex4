#include "Card.h"

Card::Card(CardType type, const CardStats &stats)
    : m_effect(type), m_stats(stats) {}

void Card::applyEncounter(Player &player) const 
{
  bool res;
  switch (m_effect) 
  {
    case CardType::Gremlin:
      res = player.getAttackStrength() >= m_stats.force;
      if (res) 
      {
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), "Germlin");
        break;
      }
      player.damage(m_stats.hpLossOnDefeat);
      printLossBattle(player.getName(), "Germlin");
      break;

    case CardType::Witch:
      res = player.getAttackStrength() >= m_stats.force;
      if(res)
      {
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), "Witch");
        break;
      }
      player.damage(m_stats.hpLossOnDefeat);
      player.buff(-1);
      printLossBattle(player.getName(), "Witch");
      break;

    case CardType::Dragon:
      res = player.getAttackStrength() >= m_stats.force;
      if(res)
      {
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName(), "Dragon");
        break;
      }
      player.damage(player.getHP());
      printLossBattle(player.getName(), "Dragon");
      break;

    case CardType::Merchant:
      printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
      int num_merchant;
      while(!(std::cin>>num_merchant)||num_merchant<0||num_merchant>2)
      {
        printInvalidInput();
      }
      switch(num_merchant)
      {
        case 0:
          printMerchantSummary(std::cout,player.getName(),0,0);
          break;
        case 1:
          if(player.pay(m_stats.cost))
          {
            printMerchantSummary(std::cout,player.getName(),1,m_stats.cost);
          }
          else
          {
            printMerchantInsufficientCoins(std::cout);
          }
          break;
        case 2:
          if(player.pay(m_stats.cost2))
            {
            printMerchantSummary(std::cout,player.getName(),2,m_stats.cost2);
            }
            else
            {
              printMerchantInsufficientCoins(std::cout);
            }
            break;
      }
      break;
    case CardType::Treasure:
      printTreasureMessage();
      player.addCoins(m_stats.loot);
      break;
    case CardType::Well:
      bool isNinja=player.getClass()=="Ninja";
      printWellMessage(isNinja);
      if(!isNinja)
      {
        player.damage(m_stats.hpLossOnDefeat);
      }
      break;
    case CardType::Barfight:
      bool isWarrior = player.getClass()=="Warrior";
      printBarfightMessage(isWarrior);
      if(!isWarrior)
      {
        player.damage(m_stats.hpLossOnDefeat);
      }
      break;
    case CardType::Mana:
      bool isHealer= player.getClass()=="Healer";
      printManaMessage(isHealer);
      if(isHealer)
      {
        player.heal(m_stats.heal);
      }
      break;
  }
  return;
}
int Card::getForce() const
{
  return m_stats.force;

}
int Card::getDamage() const
{
  return m_stats.hpLossOnDefeat;

}
int Card::getLoot() const
{
  return m_stats.loot;

}

/*
void Card::printInfo() const
 {
  switch (m_effect) {
  case CardType::Battle:
    printBattleCardInfo(m_stats);
    break;
  case CardType::Heal:
    printHealCardInfo(m_stats);
    break;
  case CardType::Buff:
    printBuffCardInfo(m_stats);
    break;
  case CardType::Treasure:
    printTreasureCardInfo(m_stats);
    break;
  }
  return;
}
*/

std::string Card::getName() const
{
  switch(m_effect)
  {
    case CardType::Gremlin:
      return "Gremlin";
    case CardType::Witch:
      return "Witch";
    case CardType::Dragon:
      return "Dragon";
    case CardType::Merchant:
      return "Merchant";
    case CardType::Treasure:
      return "Treasure";
    case CardType::Well:
      return "Well";
    case CardType::Barfight:
      return "Barfight";
    case CardType::Mana:
      return "Mana";
    default:
      return "Undefined Card Type";
  }
}


std::ostream& Card::operator<<(std::ostream &os)
{
  printCardDetails(os, getName()); 
  printEndOfCardDetails(os);
  return os;
}