#pragma once
#include <string>
#include <vector>
#include "Attack.h"
using namespace std;

// Mythikin creature class
class Mythikin
{
private:
    string name;
    bool wild;
    string type;
    int level;
    int speed;
    int maxHP;
    int HP;         // Current HP
    double attackX; // Attack multiplier
    vector<Attack> attacks;

public:
    // Constructors:
    Mythikin(string name, bool wild, string type, int level, int speed, int HP, double attackX)
        : name(name), wild(wild), type(type), level(level), speed(speed), maxHP(HP), HP(HP), attackX(attackX) {}

    // level and attackX set to 1
    Mythikin(string name, bool wild, string type, int speed, int HP)
        : name(name), wild(wild), type(type), level(1), speed(speed), maxHP(HP), HP(HP), attackX(1) {}

    // Default constructor
    Mythikin() : name("Munchikin"), wild("false"), type("normal"), level(1), speed(50), maxHP(100), HP(100), attackX(1) {}

    bool isKnocked() const { return HP <= 0; }
    // Getters
    string getName() const { return name; }
    bool isWild() const { return wild; }
    string getType() const { return type; }
    int getLevel() const { return level; }
    int getSpeed() const { return speed; }
    int getMaxHP() const { return maxHP; }
    int getHP() const { return HP; }
    int getAttackMultiplier() const { return attackX; }
    vector<Attack> getAttacks() const { return attacks; }

    // Setters
    void setName(string name) { this->name = name; }
    void setWild(bool wild) { this->wild = wild; }
    void setType(string type) { this->type = type; }
    void setLevel(int level) { this->level = level; }
    void setSpeed(int speed) { this->speed = speed; }
    void setMaxHP(int maxHP) { this->maxHP = maxHP; }
    void setHP(int HP) { this->HP = HP; }
    void setAttackMultiplier(int attackX) { this->attackX = attackX; }
    void addAttack(Attack attack) { attacks.push_back(attack); }
};