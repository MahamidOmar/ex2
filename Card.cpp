

#include "Card.h"
#include "utilities.h"

Card::Card(CardType type, const CardStats& stats)
{
    this->m_effect = type;
    this->m_stats = stats;
    m_stats.loot = (m_stats.loot < 0) ? 0 : m_stats.loot;
    m_stats.cost = (m_stats.cost < 0) ? 0 : m_stats.cost;
    m_stats.force = (m_stats.force < 0) ? 0 : m_stats.force;
    m_stats.hpLossOnDefeat = (m_stats.hpLossOnDefeat < 0) ? 0 : m_stats.hpLossOnDefeat;
    m_stats.buff = (m_stats.buff < 0) ? 0 : m_stats.buff;
    m_stats.heal = (m_stats.heal < 0) ? 0 : m_stats.heal;
}

void Card::applyEncounter(Player& player) const {
    if (m_effect == CardType::Heal)
    {
        if (player.pay(this->m_stats.cost))
        {
            player.heal(this->m_stats.heal);
        }
    }
    else
    {
        if (m_effect == CardType::Buff)
        {
            if (player.pay(this->m_stats.cost))
            {
                player.buff(this->m_stats.buff);
            }
        }
        else
        {
            if (m_effect == CardType::Treasure)
            {
                player.addCoins(this->m_stats.loot);
            }
            else
            {
                int attackStrength = player.getAttackStrength();
                if (attackStrength >= this->m_stats.force)
                {
                    player.levelUp();
                    player.addCoins(this->m_stats.loot);
                    printBattleResult(true);
                }
                else
                {
                    player.damage(this->m_stats.hpLossOnDefeat);
                    printBattleResult(false);
                }
            }
        }
    }
}

void Card::printInfo() const
{
    if(this->m_effect == CardType::Buff)
    {
        printBuffCardInfo(this->m_stats);
    }
    else
    {
        if(this->m_effect == CardType::Heal)
        {
            printHealCardInfo(this->m_stats);
        }
        else
        {
            if (this->m_effect == CardType::Battle)
            {
                printBattleCardInfo(this->m_stats);
            }
            else
            {
                printTreasureCardInfo(this->m_stats);
            }
        }
    }
}


