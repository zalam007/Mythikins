#pragma once
#include <string>
using namespace std;

class Attack
{
private:
    string name;
    string type;
    int power;
    int accuracy;
    int maxMM; // max moves
    int MM;    // mythican moves left

public:
    Attack(string name, string type, int power, int accuracy, int MM)
        : name(name), type(type), power(power), accuracy(accuracy), maxMM(MM), MM(MM) {}

    Attack() : name("nibble"), type("normal"), power(5), accuracy(80), maxMM(20), MM(20) {}

    // Getters
    string getName() const { return name; }
    string getType() const { return type; }
    int getPower() const { return power; }
    int getAccuracy() const { return accuracy; }
    int getMaxMM() const { return maxMM; }
    int getMM() const { return MM; }

    // Setters
    void setName(const string &name) { this->name = name; }
    void setType(const string &type) { this->type = type; }
    void setPower(int power) { this->power = power; }
    void setAccuracy(int accuracy) { this->accuracy = accuracy; }
    void setMM(int MM) { this->MM = MM; }
};