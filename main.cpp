#include "GameManager.h"

#include <iostream>
#include <string>
using namespace std;

class Warrior : public Character {
public:
    Warrior(string n) : Character(n, 1, 100, 30, 20) {}
    void attackTarget(Character& target) override {
        int damage = attackPower - target.getDefense();
        if (damage < 0) damage = 0;
        target.reduceHealth(damage);
    }
    void useSpecialAbility(Character& target) override {
        if (specialCooldown == 0) {
            attackPower += 15;
            defensePower -= 5;
            specialCooldown = 3;
        }
    }
    string getClassName() const override {
        return "Warrior";
    }
};

class Mage : public Character {
public:
    Mage(string n) : Character(n, 1, 80, 40, 10) {}
    void attackTarget(Character& target) override {
        int damage = attackPower - target.getDefense();
        if (damage < 0) damage = 0;
        target.reduceHealth(damage);
    }
    void useSpecialAbility(Character& target) override {
        if (specialCooldown == 0) {
            target.reduceHealth(30);
            specialCooldown = 2;
        }
    }
    string getClassName() const override {
        return "Mage";
    }
};

class Archer : public Character {
public:
    Archer(string n) : Character(n, 1, 90, 35, 15) {}
    void attackTarget(Character& target) override {
        int damage = attackPower - target.getDefense();
        if (damage < 0) damage = 0;
        target.reduceHealth(damage);
    }
    void useSpecialAbility(Character& target) override {
        if (specialCooldown == 0) {
            attackPower += 10;
            specialCooldown = 2;
        }
    }
    string getClassName() const override {
        return "Archer";
    }
};

Character* createCharacter(int choice, const string& name) {
    switch (choice) {
    case 1: return new Warrior(name);
    case 2: return new Mage(name);
    case 3: return new Archer(name);
    default: return new Warrior(name);
    }
}

int main() {
    GameManager game;

    cout << "What kind of hero would you like to play as?" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Archer" << endl;
    int userChoice;
    cin >> userChoice;

    string userName;
    cout << "What will be your character's name? ";
    cin >> userName;
    Character* user = createCharacter(userChoice, userName);

    cout << "\nNow, pick your opponent's class:" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Archer" << endl;
    int aiChoice;
    cin >> aiChoice;

    string aiName;
    cout << "What will your opponent's name be? ";
    cin >> aiName;
    Character* opponent = createCharacter(aiChoice, aiName);

    cout << "\nWhere do you want to fight?" << endl;
    cout << "1. Molten Pit (FIRE)" << endl;
    cout << "2. Frozen Lake (ICE)" << endl;
    cout << "3. Thunder Dome (ELECTRIC)" << endl;
    int arenaChoice;
    cin >> arenaChoice;

    Arena* arena;
    if (arenaChoice == 1)
        arena = new Arena("Molten Pit", Config::ArenaType::FIRE);
    else if (arenaChoice == 2)
        arena = new Arena("Frozen Lake", Config::ArenaType::ICE);
    else
        arena = new Arena("Thunder Dome", Config::ArenaType::ELECTRIC);

    game.addCharacter(user);
    game.addCharacter(opponent);
    game.addArena(*arena);

    game.startBattle();

    delete arena;
    return 0;
}
