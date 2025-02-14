

#include <iostream>
#include "Player.h"

Player::Player(string name, int maxHP , int force):
        m_name(name), m_level(1), m_force(force), m_maxHP(maxHP), m_HP(maxHP), m_coins(0)
{
    if(maxHP < 0)
    {
        m_maxHP = 100;
        m_HP = 100;
    }
    if(force < 0)
    {
        m_force = 5;
    }
}

void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}

void Player::levelUp()
{
    if(m_level == 10)
    {
        return;
    }
    m_level++;
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int toBuff)
{
    if(toBuff <= 0)
    {
        return;
    }
    m_force += toBuff;
}

void Player::heal(int hp)
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

void Player::damage(int damage)
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

bool Player::isKnockedOut() const
{
    return m_HP == 0;
}

void Player::addCoins(int coins)
{
    if(coins < 0)
    {
        return;
    }
    m_coins += coins;
}

bool Player::pay(int coins)
{
    if(coins < 0)
    {
        return true;
    }
    if(coins > m_coins)
    {
        return false;
    }
    m_coins -= coins;
    return true;
}

int Player::getAttackStrength()const
{
    return m_level + m_force;
}



