#pragma once
#include "Mythikin.h"
#include "Location.h"
#include "WildBattle.h"
#include "Battle.h"

class WildLocation : public Location
{
private:
    vector<Mythikin> mythikinSpawn;
    int spawnRate;

public:
    WildLocation(const string &name): Location(name) {}

    WildLocation(const string &name, const vector<Location *> &neighbors, vector<Mythikin> MythikinList, int spawnRate) : Location(name, neighbors), mythikinSpawn(MythikinList), spawnRate(spawnRate) {}

    WildLocation(const string &name, const vector<Location *> &neighbors, const vector<NPC> &npcs, vector<Mythikin> MythikinList, int spawnRate) : Location(name, neighbors, npcs), mythikinSpawn(MythikinList), spawnRate(spawnRate) {}

    int getSpawnRate() const;

    vector<Mythikin> getMythikinSpawn() const;

    void addMythikin(const Mythikin &name);

    void removeMythikin(const string &name);

    void setSpawnRate(int spawnRate);

    void encounter() const;
};