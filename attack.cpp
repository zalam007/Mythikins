#include <string>
#include "mythikin.cpp"
using namespace std;

class Attack {
private:
    string name;
    string type;
    int power;
    int accuracy;
    int maxMM;         // max moves
    int MM;            // moves left

public:
    Attack(string name, string type, int power, int accuracy, int MM)
        : name(name), type(type), power(power), accuracy(accuracy), maxMM(MM), MM(MM) {}

    Attack() : name("bitch slap"), type("normal"), power(10), accuracy(100), maxMM(20), MM(20) {}

    int damage(const Mythikin& otherMythikin) {
        return 0; // Placeholder return value
    }

    // Getters
    string getName() const { return name; }
    string getType() const { return type; }
    int getPower() const { return power; }
    int getAccuracy() const { return accuracy; }
    int getMaxMM() const { return maxMM; }
    int getMM() const { return MM; }

    // Setters
    void setName(const string& name) { this->name = name; }
    void setType(const string& type) { this->type = type; }
    void setPower(int power) { this->power = power; }
    void setAccuracy(int accuracy) { this->accuracy = accuracy; }
    void setMM(int MM) { this->MM = MM; }
};