#include "GameManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

GameManager::GameManager() {
    battleLog.open("battleLog.txt", ios::app);
}

void GameManager::log(const string& message) {
    if (battleLog.is_open()) {
        std::time_t currentTime = std::time(nullptr);
        char timeBuffer[100];
        ctime_s(timeBuffer, sizeof(timeBuffer), &currentTime);
        battleLog << "[" << timeBuffer << "] " << message << endl;
    }
}

GameManager::~GameManager() {
    delete characters[0];
    delete characters[1];
    delete arena;
    battleLog.close();
}

void GameManager::addArena(const Arena& arenaObj) {
    if (!arena) {
        arena = new Arena(arenaObj);
    }
}

void GameManager::addCharacter(Character* characterObj) {
    if (!characters[0]) {
        characters[0] = characterObj;
    }
    else if (!characters[1]) {
        characters[1] = characterObj;
    }
}

void GameManager::startBattle() {
    if (!characters[0] || !characters[1]) return;

    Character* player = characters[0];
    Character* enemy = characters[1];

    cout << "Battle begins between " << player->getName() << " (You) and " << enemy->getName() << " (AI)!" << endl;
    log("Battle started: " + player->getName() + " vs " + enemy->getName());

    int turn = 0;
    while (player->isAlive() && enemy->isAlive()) {
        if (turn % 2 == 0) {

            cout << "Your turn! Choose an action:" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Use Special Ability" << endl;
            cout << "> ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                player->attackTarget(*enemy);
                cout << player->getName() << " attacked " << enemy->getName() << "!" << endl;
                log(player->getName() + " attacked " + enemy->getName());
            }
            else if (choice == 2) {
                player->useSpecialAbility(*enemy);
                cout << player->getName() << " used a special ability!" << endl;
                log(player->getName() + " used special ability on " + enemy->getName());
            }
            else {
                cout << "Invalid choice. Turn skipped." << endl;
                log(player->getName() + " made an invalid choice.");
            }
        }
        else {

            cout << enemy->getName() << "'s turn (AI):" << endl;
            if (enemy->getSpecialCooldown() == 0) {
                enemy->useSpecialAbility(*player);
                cout << enemy->getName() << " used a special ability!" << endl;
                log(enemy->getName() + " used special ability on " + player->getName());
            }
            else {
                enemy->attackTarget(*player);
                cout << enemy->getName() << " attacked " << player->getName() << "!" << endl;
                log(enemy->getName() + " attacked " + player->getName());
            }
        }

        cout << "Current Arena: " << arena->getName() << endl;
        cout << player->getName() << " HP: " << player->getHealth() << endl;
        cout << enemy->getName() << " HP: " << enemy->getHealth() << endl;

        turn++;
    }

    string winner = player->isAlive() ? player->getName() : enemy->getName();
    cout << "Battle Over! Winner: " << winner << endl;
    log("Battle Over! Winner: " + winner);
}
