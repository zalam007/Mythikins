#pragma once

#include <vector>
#include <string>
#include "NPC.h"
using namespace std;

class Location
{
private:
    string name;
    vector<Location *> neighborLocations;
    vector<NPC> NPCSpawn;

public:
    Location() {}

    Location(const string &name) : name(name) {}

    Location(const string &name, const vector<Location *> &neighbors) : name(name), neighborLocations(neighbors) {}

    Location(const string &name, const vector<Location *> &neighbors, const vector<NPC> &npcs) : name(name), neighborLocations(neighbors), NPCSpawn(npcs) {}

    string getName() const
    {
        return name;
    }

    vector<Location *> getNeighbors() const
    {
        return neighborLocations;
    }

    vector<NPC> getNPCList() const
    {
        return NPCSpawn;
    }

    void setName(const string &name)
    {
        this->name = name;
    }

    void addNPC(const NPC &npc)
    {
        NPCSpawn.push_back(npc);
    }

    void removeNPC(const string &name);

    void addLocation(Location *location)
    {
        neighborLocations.push_back(location);
    }

    void removeLocation(const string &name);
};
