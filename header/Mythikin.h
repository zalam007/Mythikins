#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Attack.h"
using namespace std;

// Mythikin creature class (similar to a Pokimon)
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
    //CONSTRUCTORS:
    Mythikin(string name, bool wild, string type, int level, int speed, int HP, double attackX)
        : name(name), wild(wild), type(type), level(level), speed(speed), maxHP(HP), HP(HP), attackX(attackX) {}

    // wild=true attackX=1
    Mythikin(string name, string type, int level, int speed, int HP)
        : name(name), wild(true), type(type), level(level), speed(speed), maxHP(HP), HP(HP), attackX(1) {}

    // wild=true level&attackX=1
    Mythikin(string name, string type, int speed, int HP)
        : name(name), wild(true), type(type), level(1), speed(speed), maxHP(HP), HP(HP), attackX(1) {}

    // Default constructor
    Mythikin() : name("Default-Munchikin"), wild("false"), type("normal"), level(1), speed(50), maxHP(100), HP(100), attackX(1) {}
  
    //Copy Constructor
    Mythikin(const Mythikin& other) : name(other.name), wild(other.wild), type(other.type), level(other.level), speed(other.speed), maxHP(other.maxHP), HP(other.HP), attackX(other.attackX), attacks(other.attacks) {}
    //TODO: Implemetn Copy assignment

    //GETTERS:
    string getName() const { return name; }
    bool isWild() const { return wild; }
    string getType() const { return type; }
    int getLevel() const { return level; }
    int getSpeed() const { return speed; }
    int getHP() const { return HP; }
    int getMaxHP() const { return maxHP; }
    bool isKnocked() const { return HP <= 0; }
    int getAttackX() const { return attackX; }
    vector<Attack> getAttacks() const { return attacks; }

    //SETTERS:
    void setName(string name) { this->name = name; }
    void setWild(bool wild) { this->wild = wild; }
    void setType(string type) { this->type = type; }
    void setLevel(int level) { this->level = level; }
    void setSpeed(int speed) { this->speed = speed; }
    void setMaxHP(int maxHP) { this->maxHP = maxHP; }
    void setHP(int HP) {
        if(HP >= maxHP) { cerr << "set HP over max, set to max"; this->HP = maxHP; }    //HP set to high
        else { this->HP = HP; } // HP set
    }
    void setAttackX(int attackX) { this->attackX = attackX; }
    void addAttack(Attack attack) { attacks.push_back(attack); }
};