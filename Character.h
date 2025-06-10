#pragma once
#include <string>
#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int level;
    int health;
    int attackPower;
    int defensePower;
    int specialCooldown = 0;

public:
    Character(string charName, int charLevel, int hp, int atk, int def);
    virtual ~Character() = default;

    int getSpecialCooldown() const {
        return specialCooldown;
    }

    virtual void attackTarget(Character& target) = 0;
    virtual void useSpecialAbility(Character& target) = 0;
    virtual string getClassName() const = 0;

    bool isAlive() const;
    int getAttack() const;
    int getDefense() const;
    int getHealth() const;
    string getName() const;

    void reduceHealth(int damage);
    void applyBuff(double multiplier);

    Character& operator+(Character& other);
    bool operator==(Character& other);
    Character& operator-(Character& other);

    friend ostream& operator<<(ostream& os, const Character& c);
};
