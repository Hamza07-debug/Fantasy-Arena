#include "Arena.h"
#include<string>
Arena::Arena(string n, Config::ArenaType t) : name(n), type(t) {}

void Arena::addCharacter(Character* c) {
    if (!ch1)
        ch1 = c;
    else if (!ch2)
        ch2 = c;

}

void Arena::applyEnvironmentEffects() {

    if (ch1) {

    }
    if (ch2) {

    }
}

string Arena::getName() const {
    return name;
}
