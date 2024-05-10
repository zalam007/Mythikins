#include <string>
#include <vector>
using namespace std;

struct Attack {
    // Attributes and methods for the Attack struct
};

// Mythikin creature class
class Mythikin {
private:
    string name;
    string type;
    int level;
    int maxHP;
    int HP;         // Current HP
    int attackX;    // Attack multiplier
    vector<Attack> attacks;

public:
    // Constructors
    Mythikin(string name, string type, int level, int HP, int attackX, vector<Attack> attacks)
        : name(name), type(type), level(level), maxHP(HP), HP(HP), attackX(attackX), attacks(attacks) {}

    Mythikin(string name, string type, int HP, vector<Attack> attacks)  //level and attackX set to 1
        : name(name), type(type), level(1), maxHP(HP), HP(HP), attackX(1), attacks(attacks) {}

    Mythikin() : name("mysteryMythikin"), type("normal"), level(1), maxHP(100), HP(100), attackX(1), attacks(vector<Attack>()) {}

    // Getters
    string getName() { return name; }
    string getType() { return type; }
    int getMaxHP() { return maxHP; }
    int getHP() { return HP; }
    int getAttackMultiplier() { return attackX; }
    vector<Attack> getAttacks() { return attacks; }

    // Setters
    void setName(string name) { name = name; }
    void setType(string type) { type = type; }
    void setHP(int HP) { HP = HP; }
    void setAttackMultiplier(int attackX) { attackX = attackX; }

    void addAttack(Attack attack) {
        attacks.push_back(attack);
    }
};