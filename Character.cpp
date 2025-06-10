#include "Character.h"
#include<fstream>
#include<iomanip>
#include <iostream>
using namespace std;

Character::Character(string charName, int charLevel, int hp, int atk, int def)
    : name(charName), level(charLevel), health(hp), attackPower(atk), defensePower(def) {}

bool Character::isAlive() const {
    return health > 0;
}

int Character::getAttack() const {
    return attackPower;
}

int Character::getDefense() const {
    return defensePower;
}

int Character::getHealth() const {
    return health;
}

string Character::getName() const {
    return name;
}

void Character::reduceHealth(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

void Character::applyBuff(double multiplier) {
    attackPower = static_cast<int>(attackPower * multiplier);
    defensePower = static_cast<int>(defensePower * multiplier);
}

Character& Character::operator+(Character& other) {
    this->attackPower += other.attackPower / 2;
    return *this;
}

bool Character::operator==(Character& other) {
    return (attackPower + defensePower + level) == (other.attackPower + other.defensePower + other.level);
}

Character& Character::operator-(Character& other) {
    int damage = 10;
    other.reduceHealth(damage);
    this->health += damage;
    return *this;
}

ostream& operator<<(ostream& os, const Character& c) {
    os << c.name << " [" << c.getClassName() << "] | HP: " << c.health
        << ", ATK: " << c.attackPower << ", DEF: " << c.defensePower << endl;
    return os;
}
