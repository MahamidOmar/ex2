

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include <string>
#include "utilities.h"
using std::string;

class Player
{
public:
    Player(string name, int maxHP = 100, int force = 5):
        m_name(name), m_level(1), m_force(force), m_maxHP(maxHP), m_HP(maxHP), m_coins(0) {};

    ~Player() = default;
    Player(const Player& player)
    {
        this->m_name = player.m_name;
        this->m_level = player.m_level;
        this->m_force = player.m_force;
        this->m_maxHP = player.m_maxHP;
        this->m_HP = player.m_HP;
        this->m_coins = player.m_coins;
    }

    Player& operator=(const Player& player)
    {
        this->m_name = player.m_name;
        this->m_level = player.m_level;
        this->m_force = player.m_force;
        this->m_maxHP = player.m_maxHP;
        this->m_HP = player.m_HP;
        this->m_coins = player.m_coins;
        return *this;
    }

    void printInfo() const
    {
        printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
    }

    void levelUp()
    {
        if(m_level == 10)
        {
            return;
        }
        m_level++;
    }

    int getLevel() const
    {
        return m_level;
    }

    void buff(int toBuff)
    {
        if(toBuff <= 0)
        {
            return;
        }
        m_force += toBuff;
    }

    void heal(int hp)
    {
        if(hp <= 0)
        {
            return;
        }
        m_HP += hp;
        if(m_HP > m_maxHP)
        {
            m_HP = m_maxHP;
        }
    }

    void damage(int damage)
    {
        if(damage <= 0)
        {
            return;
        }
        m_HP -= damage;
        if(m_HP < 0)
        {
            m_HP = 0;
        }
    }

    bool isKnockedOut() const
    {
        return m_HP == 0;
    }

    void addCoins(int coins)
    {
        m_coins += coins;
    }

    bool pay(int coins)
    {
        if(coins > m_coins)
        {
            return false;
        }
        m_coins -= coins;
        return true;
    }

    int getAttackStrength()const
    {
        return m_level + m_force;
    }



private:
    string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
};


#endif //PLAYER_H
