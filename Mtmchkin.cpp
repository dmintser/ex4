#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string &fileName):
    m_N_rounds(0)
{
    printStartGameMessage();
    int input;
    printEnterTeamSizeMessage();
    std::cin>>input;//how to check if integer
    while(input<2||input>6)
    {
        printInvalidTeamSize();
        std::cin>>input;
    }

    m_size=input;
    Player* leaderBoard = new Player[input];//throw bad alloc
    m_leaderBoaed=leaderBoard;

    std::string name, n_class;
    for(int i=0;i<input;i++)
    {
        std::cin>>name;//needs to be checked
        std::cin>>n_class;//needs to be checked
        Player* player = new Player(name,n_class);
        m_leaderBoaed[i]=player;
        m_players->push(player);
    }


    std::ifstream source(fileName);
    char line[256];
    while(source.getline(line,sizeof(line)))
    {
        switch(line)
        {
            case "Gremlin":
                m_deck->push(&m_gremlin);
                break;
            case "Witch":
                m_deck->push(&m_witch);
                break;
            case "Dragon":
                m_deck->push(&m_dragon);
                break;
            case "Merchant":
                m_deck->push(&m_merchant);
                break;
            case "Treasure":
                m_deck->push(&m_treasure);
                break;
            case "Well":
                m_deck->push(&m_well);
                break;
            case "Barfight":
                m_deck->push(&m_barfight);
                break;
            case "Mana":
                m_deck->push(&m_mana);
                break;
            default:
                //probably throw some exeption
            
        }
    }



}

int Mtmchkin::getNumberOfRounds() const
{
    return m_N_rounds;
}


