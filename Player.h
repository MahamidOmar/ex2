

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
    Player(const Player& player);

    Player& operator=(const Player& player);

    void printInfo() const;

    void levelUp();

    int getLevel() const;

    void buff(int toBuff);

    void heal(int hp);

    void damage(int damage);

    bool isKnockedOut() const;

    void addCoins(int coins);

    bool pay(int coins);

    int getAttackStrength()const;


private:
    string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
};


#endif //PLAYER_H
