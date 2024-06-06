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
    Location(const string &name) : name(name) {}

    Location(const string &name, const vector<Location *> &neighbors, const vector<NPC> &npcs) : name(name), neighborLocations(neighbors), NPCSpawn(npcs) {}

    string getName()
    {
        return name;
    }

    vector<Location *> getNeighbors()
    {
        return neighborLocations;
    }

    vector<NPC> getNPCList()
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

    void removeNPC(const string &name)
    {
        for (int i = 0; i < NPCSpawn.size(); ++i)
        {
            if (NPCSpawn[i].getName() == name)
            {
                NPCSpawn.erase(NPCSpawn.begin() + i);
            }
        }
    }

    void addLocation(Location *location)
    {
        neighborLocations.push_back(location);
    }

    void removeLocation(const string &name)
    {
        for (int i = 0; i < neighborLocations.size(); ++i)
        {
            if (neighborLocations[i]->getName() == name)
            {
                delete neighborLocations[i];
                neighborLocations.erase(neighborLocations.begin() + i);
            }
        }
    }
};
