
#include "Arena.h"
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

class GameManager {
private:
    Arena* arena = nullptr;
    Character* characters[2] = { nullptr };
    ofstream battleLog;

    void log(const string& message);

public:
    GameManager();
    ~GameManager();

    void addArena(const Arena& arenaObj);
    void addCharacter(Character* characterObj);
    void startBattle();
};
