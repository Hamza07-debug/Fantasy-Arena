
#include <string>
#include "Character.h"
#include "Config.h"
using namespace std;
class Arena {
private:
    string name;
    Config::ArenaType type;
    Character* ch1 = nullptr;
    Character* ch2 = nullptr;
public:
    Arena(string n, Config::ArenaType t);
    void addCharacter(Character* c);
    void applyEnvironmentEffects();
    string getName() const;
};
