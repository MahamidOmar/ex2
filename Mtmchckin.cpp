

#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"
#include <iostream>

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
        m_player(playerName), m_numberOfCards(numOfCards), m_status(GameStatus::MidGame), m_nextCard(0)
{
    m_cards = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i)
    {
        m_cards[i] = cardsArray[i];
    }
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}

void Mtmchkin::playNextCard()
{
    m_cards[m_nextCard].printInfo();
    m_cards[m_nextCard].applyEncounter(m_player);
    m_player.printInfo();

    if(m_nextCard == m_numberOfCards - 1)
    {
        m_nextCard = 0;
    }
    else
    {
        m_nextCard++;
    }
}

bool Mtmchkin::isOver() const
{
    return m_status == GameStatus::Win || m_status == GameStatus::Loss;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}


