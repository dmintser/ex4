#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include <queue>
#include <deque>
#include "utilities.h"
#include "Players/Player.h"
#include "Cards/Card.h"

class Mtmchkin{

Card m_gremlin(Gremlin,Gremlin_stats(5,2,10,0,0,0,0));
Card m_witch(Witch,Witch_stats(11,2,10,0,0,0,-1));
Card m_dragon(Dragon,Dragon_stats(25,1000,0,0,0,0,0));
Card m_merchant(Merchant,Merchant_stats(0,0,0,5,10,1,1));
Card m_treasure(Treasure,Treasure_stats(0,10,0,0,0,0,0));
Card m_well(Well,Well_stats(0,0,10,0,0,0,0));
Card m_barfight(Barfight,Barfight_stats(0,0,10,0,0,0,0));
Card m_mana(Mana,Mana_stats(0,0,0,0,0,10,0));

int m_N_rounds;
int m_size=0;
Player* m_leaderBoaed;
std::queue<Card*> *m_deck;
std::queue<Player*> *m_players;

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};



#endif /* MTMCHKIN_H_ */
