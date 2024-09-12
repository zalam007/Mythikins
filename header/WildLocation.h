#pragma once
#include <ctime>
#include "Mythikin.h"
#include "Location.h"
#include "WildBattleMenu.h"
#include "BattleMenu.h"

class WildLocation : public Location
{
private:
    vector<NPC> battlers;
    vector<Mythikin> wildMythikin;
    int spawnRate = 50;

public:
    WildLocation(const string &name) : Location(name) {}

    WildLocation(const string &name, const vector<Location *> &neighbors, vector<Mythikin> MythikinList, int spawnRate) : Location(name, neighbors), wildMythikin(MythikinList), spawnRate(spawnRate) {}

    WildLocation(const string &name, const vector<Location *> &neighbors, const vector<NPC*> &npcs, vector<Mythikin> MythikinList, int spawnRate) : Location(name, neighbors, npcs), wildMythikin(MythikinList), spawnRate(spawnRate) {}

    int getSpawnRate() const;

    vector<Mythikin> getMythikinSpawn() const;

    vector<NPC> getBattlerSpawn() const;

    void addMythikin(const Mythikin &name);

    void removeMythikin(const string &name);

    void addBattler(const NPC &name);

    void removeBattler(const string &name);

    void setSpawnRate(int spawnRate);

    void encounter(Player &mainCharacter, PC &playerPC) const;

    string getType() const override{
        return "WildLocation";
    }
};