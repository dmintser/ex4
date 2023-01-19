#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string &fileName):
    m_N_rounds(0)  
{
    printStartGameMessage();
    int input;
    printEnterTeamSizeMessage();
    while(!(std::cin>>input)&&(input<2||input>6))
    {
        printInvalidTeamSize();
    }

    m_size=input;
    Player** leaderBoard = new Player*[input];//throw bad alloc
    m_leaderBoaed=leaderBoard;

    char* name, *n_class;
    for(int i=0;i<input;i++)
    {
        printInsertPlayerMessage();
        std::cin>>name;
        while(!valid_name(name))
        {
            printInvalidName();
            std::cin>>name;
        }

        std::cin>>n_class;
        while(!valid_class(n_class))
        {
            printInvalidClass();
            std::cin>>n_class;
        }

        if(n_class=="Ninja")
        {
            Ninja* ninja = new Ninja(name);
            m_leaderBoaed[i]= ninja;
            m_players->push(ninja);
        }
                
        if(n_class=="Healer")
        {
            Healer* healer = new Healer(name);
            m_leaderBoaed[i]= healer;
            m_players->push(healer);
        }

        if(n_class=="Warrior")
        {
            Warrior* warrior = new Warrior(name);
            m_leaderBoaed[i]= warrior;
            m_players->push(warrior);
        }

    }

    std::ifstream source(fileName);
    char line[256];
    while(source.getline(line,sizeof(line)))
    {
        if(line=="Gremlin")
        {
            Gremlin* gremlin = new Gremlin();
            m_deck->push(gremlin);
        }

        else if(line=="Witch")
        {
            Witch* witch = new Witch();
            m_deck->push(witch);
        }

        else if(line=="Dragon")
        {
            Dragon* dragon = new Dragon();
            m_deck->push(dragon);
        }

        else if(line=="Merchant")
        {
            Merchant* merchant= new Merchant();
            m_deck->push(merchant);
        }

        else if(line=="Treasure")
        {
            Treasure* treasure = new Treasure();
            m_deck->push(treasure);
        }

        else if(line=="Well")
        {
            Well* well = new Well();
            m_deck->push(well);
        }

        else if(line=="Barfight")
        {
            Barfight* barfight = new Barfight();
            m_deck->push(barfight);
        }

        else if(line=="Mana")
        {
            Mana* mana = new Mana();
            m_deck->push(mana);
        }

        else{
            //what should we do in case of invalid cardType?
        }
    }

}

int Mtmchkin::getNumberOfRounds() const
{
    return m_N_rounds;
}


// ****** UTILITIES ***** //

bool valid_name(std::string name)
{
    int len = name.length();
    if(!len||len>15)
    {
        return false;
    }

    for(int i=0; i<len; i++)
    {
        if(!((name[i]>'a'&&name[i]<'z')||(name[i]>'A'&&name[i]<'Z')))
        {
            return false;
        }
    }
}


bool valid_class(std::string n_class)
{
    return (n_class=="Ninja"||n_class=="Warrior"||n_class=="Healer");
}



