#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Attack.h"
#include <map>
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
    Mythikin(string name, bool wild, string type, int level, int speed, int HP)
        : name(name), wild(wild), type(type), level(level), speed(speed), maxHP(HP), HP(HP), attackX(1) {}

    // wild=true attackX=1
    Mythikin(string name, string type, int level, int speed, int HP)
        : name(name), wild(true), type(type), level(level), speed(speed), maxHP(HP), HP(HP), attackX(1) {}

    // wild=true level&attackX=1
    Mythikin(string name, string type, int speed, int HP)
        : name(name), wild(true), type(type), level(1), speed(speed), maxHP(HP), HP(HP), attackX(1) {}

    // Default constructor
    Mythikin() : name("Default-Munchikin"), wild("false"), type("normal"), level(1), speed(50), maxHP(100), HP(100), attackX(1) {}

    //NPC Mythikin
    Mythikin(string name) : wild("false"), type("normal"), level(1), speed(50), maxHP(100), HP(100), attackX(1) {}
  
    //Copy Constructor
    Mythikin(const Mythikin& other) : name(other.name), wild(other.wild), type(other.type), level(other.level), speed(other.speed), maxHP(other.maxHP), HP(other.HP), attackX(other.attackX), attacks(other.attacks) {}
    //TODO: Implemetn Copy assignment

    //GETTERS:
    string getName() const { return name; }
    bool isWild() const { return wild; }
    string getType() const { return type; }
    int getLevel() const { return level; }
    int getSpeed() const { return speed; }
    int getMaxHP() const { return maxHP; }
    int getHP() const { return HP; }
    bool isKnocked() const { return HP <= 0; }
    double getAttackX() const { return attackX; }
    vector<Attack>& getAttacks() { return attacks; }

    //SETTERS:
    void setName(string name) { this->name = name; }
    void setWild(bool wild) { this->wild = wild; }
    void setType(string type) { this->type = type; }
    void setLevel(int level) { this->level = level; }
    void setSpeed(int speed) { this->speed = speed; }
    void setMaxHP(int maxHP) { this->maxHP = maxHP; }
    void setHP(int HP) {
        if(HP >= maxHP) { this->HP = maxHP; }    //HP set too high
        else { this->HP = HP; } // HP set
    }
    void setAttackX(double attackX) { this->attackX = attackX; }
    void addAttack(const Attack& attack) { attacks.push_back(attack); }
};

extern map<string, Mythikin*> mythikins;