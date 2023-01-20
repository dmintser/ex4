#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string &fileName):
    m_N_rounds(0)  
{
    std::ifstream source(fileName);
    int deckLine=0;
    std::string curr_card;
    if(source.is_open())
    {
        //std::cerr << "opend" << std::endl;
        while(std::getline(source, curr_card))
        {
            deckLine++;
            if(curr_card=="Gremlin")
            {
                Gremlin* gremlin = new Gremlin();
                m_deck.push(gremlin);
            }

            else if(curr_card=="Witch")
            {
                Witch* witch = new Witch();
                m_deck.push(witch);
            }

            else if(curr_card=="Dragon")
            {
                Dragon* dragon = new Dragon();
                m_deck.push(dragon);
            }

            else if(curr_card=="Merchant")
            {
                Merchant* merchant= new Merchant();
                m_deck.push(merchant);
            }

            else if(curr_card=="Treasure")
            {
                Treasure* treasure = new Treasure();
                m_deck.push(treasure);
            }

            else if(curr_card=="Well")
            {
                Well* well = new Well();
                m_deck.push(well);
            }

            else if(curr_card=="Barfight")
            {
                Barfight* barfight = new Barfight();
                m_deck.push(barfight);
            }

            else if(curr_card=="Mana")
            {
                Mana* mana = new Mana();
                m_deck.push(mana);
            }

            else
            {
                throw DeckFileFormatError(deckLine);
            }
        }
        if(deckLine<5)
        {
            throw DeckFileInvalidSize();
        }

    }
    else
    {
        throw DeckFileNotFound();
    }
    printStartGameMessage();
    int input;
    printEnterTeamSizeMessage();
    while(!(std::cin>>input)&&(input<2||input>6))
    {
        printInvalidTeamSize();
    }
    //std::queue<Player*> players_queue;
    //m_players = &players_queue;
    //std::cerr << "adress 1:" << m_players << std::endl;
    //std::queue<Card*> cards_queue;
    //m_deck = & cards_queue;
    m_size=input;
    m_start = 0;
    m_end = input - 1;
    Player** leaderBoard;
    try{
        leaderBoard = new Player*[input];//throw bad alloc
    }
    catch(std::bad_alloc &e)
    {
        std::cout << "BAD ALLOC" << std::endl;
        throw;
    }
    m_leaderBoaed=leaderBoard;
    std::string name; 
    std::string n_class;
    for(int i=0;i<input;i++)
    { 
        printInsertPlayerMessage();
        std::cin>>name;
        //std::cerr << name << std::endl;
        while(!valid_name(name))
        {
            //std::cerr << "invalid name" << std::endl;
            printInvalidName();
            std::cin>>name;
        }
        //std::cerr << name << std::endl;
        std::cin>>n_class;
        while(!valid_class(n_class))
        {
            printInvalidClass();
            std::cin>>name;
            std::cin>>n_class;
        }
        //std::cerr << n_class << std::endl;
        if(n_class=="Ninja")
        {
            //std::cerr<<"ninja!"<<std::endl;
            Player* ninja = new Ninja(name);
            m_leaderBoaed[i]= ninja;
            m_players.push(ninja);
            //std::cerr<<"pushed!"<<std::endl;
        }
                
        if(n_class=="Healer")
        {
            //std::cerr<<"healer!"<<std::endl;
            Player* healer = new Healer(name);
            m_leaderBoaed[i]= healer;
            m_players.push(healer);
            //std::cerr<<healer<<std::endl;
            
        }
        
        if(n_class=="Warrior")
        {
            //std::cerr<<"warrior!"<<std::endl;
            Player* warrior = new Warrior(name);
            m_leaderBoaed[i]= warrior;
            m_players.push(warrior);
            //std::cerr<<"pushed!"<<std::endl;
        }

    }

    


}
Mtmchkin::~Mtmchkin()
{
    delete m_leaderBoaed;
    while((!m_deck.empty()))
    {
        Card* to_delete=m_deck.front();
        delete to_delete;
        m_deck.pop();
    }
    while(!(m_players.empty()))
    {
        Player* to_delete=m_players.front();
        delete to_delete;
        m_players.pop();
    }

}

int Mtmchkin::getNumberOfRounds() const
{
    return m_N_rounds;
}

void Mtmchkin::playRound()
{
    /*
    while(!(m_deck.empty()))
    {
        std::cerr<<(*(m_deck.front()))<<std::endl;
        m_deck.pop();
    }
    exit(1);
    */
    
    m_N_rounds++;
    printRoundStartMessage(m_N_rounds);
    int num_players=m_players.size();
    for(int i=0;i<num_players;i++)
    {
        Player* to_play = m_players.front();
        //std::cerr << *to_play << std::endl;
        printTurnStartMessage(to_play->getName());
        m_players.pop();
        Card* to_encounter=m_deck.front();
        m_deck.pop();
        m_deck.push(to_encounter);
        to_encounter->applyEncounter(*to_play);
        if(to_play->doneGame()==1)
        {
            m_leaderBoaed[m_start++]=to_play;
            for(int i=m_start;i<=m_end;i++)
            {
                m_leaderBoaed[i]=m_players.front();
                m_players.pop();
                m_players.push(m_leaderBoaed[i]);
            }
        }
        else if(to_play->doneGame()==2)
        {
            m_leaderBoaed[m_end--]=to_play;
            for(int i=m_start;i<=m_end;i++)
            {
                m_leaderBoaed[i]=m_players.front();
                m_players.pop();
                m_players.push(m_leaderBoaed[i]);
            }

        }
        else
        {
            m_players.push(to_play);
        }
        //std::cerr << *to_play << std::endl;
    }
    if(isGameOver())
    {
        printGameEndMessage();
    }
    //printLeaderBoard();
}

bool Mtmchkin::isGameOver() const
{
    return(m_players.empty());
}


// ****** UTILITIES ***** //

bool valid_name(std::string name)
{
    //std::cerr << "<" << name << ">" <<std::endl;
    int len = name.length();
    if(!len||len>15)
    {
        return false;
    }

    for(int i=0; i<len; i++)
    {
        if(!((name[i]>='a'&&name[i]<='z')||(name[i]>='A'&&name[i]<='Z')))
        {
            //std::cerr << "11111" << std::endl;
            return false;
        }
    }
    return true; //to be checked
}


bool valid_class(std::string n_class)
{
    return (n_class=="Ninja"||n_class=="Warrior"||n_class=="Healer");
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    for(int i = 1; i<= m_size; i++){
        //std::cerr << "hila snobit" <<std::endl;
        printPlayerLeaderBoard(i, *m_leaderBoaed[i-1]);
    }
}


