#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string &fileName)
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
    std::string name, n_class;
    for(int i=0;i<input;i++)
    {
        std::cin>>name;//needs to be checked
        std::cin>>n_class;//needs to be checked
        m_players->push(Player(name,n_class));
    }

    Card gremlin(Gremlin,Gremlin_stats(5,2,10,0,0,0,0));
    Card witch(Witch,Witch_stats(11,2,10,0,0,0,-1));
    Card dragon(Dragon,Dragon_stats(25,1000,0,0,0,0,0));
    Card merchant(Merchant,Merchant_stats(0,0,0,5,10,1,1));
    Card treasure(Treasure,Treasure_stats(0,10,0,0,0,0,0));
    Card well(Well,Well_stats(0,0,10,0,0,0,0));
    Card barfight(Barfight,Barfight_stats(0,0,10,0,0,0,0));
    Card mana(Mana,Mana_stats(0,0,0,0,0,10,0));

    std::ifstream source(fileName);
    char line[256];
    while(source.getline(line,sizeof(line)))
    {
        switch(line)
        {
            case "Gremlin":
                m_deck->push(&gremlin);
                break;
            case "Witch":
                m_deck->push(&witch);
                break;
            case "Dragon":
                m_deck->push(&dragon);
                break;
            case "Merchant":
                m_deck->push(&merchant);
                break;
            case "Treasure":
                m_deck->push(&treasure);
                break;
            case "Well":
                m_deck->push(&well);
                break;
            case "Barfight":
                m_deck->push(&barfight);
                break;
            case "Mana":
                m_deck->push(&mana);
                break;
            default:
                //probably throw some exeption
            
        }
    }



}
