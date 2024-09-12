#pragma once

#include <vector>
#include <string>
#include "NPC.h"
#include "map"

using namespace std;

class Location {
private:
    string name;
    vector<Location *> neighborLocations;
    vector<NPC*> NPCSpawn;

public:
    Location() {}

    Location(const string &name) : name(name) {}

    Location(const string &name, const vector<Location *> &neighbors)
        : name(name), neighborLocations(neighbors) {}

    Location(const string &name, const vector<Location *> &neighbors, const vector<NPC*> &npcs)
        : name(name), neighborLocations(neighbors), NPCSpawn(npcs) {}

    ~Location() {
        NPCSpawn.clear();  // Clear vector after deletion
        neighborLocations.clear();  // Clear neighbors (no need to delete since they are pointers, but not owned)
    }

    string getName() const {
        return name;
    }

    vector<Location *> getNeighbors() const {
        return neighborLocations;
    }

    void addNeighbor(Location& newNeighbor) {
        neighborLocations.push_back(&newNeighbor);
        newNeighbor.neighborLocations.push_back(this);
    }

    vector<NPC*> getNPCList() const {
        return NPCSpawn;
    }

    NPC* getNPC(const string &name) {
        for (NPC* npc : NPCSpawn) {
            if (npc->getName() == name) {
                return npc;
            }
        }
        return nullptr;
    }

    void setName(const string &name) {
        this->name = name;
    }

    void addNPC(NPC* npc) {
        NPCSpawn.push_back(npc);
    }

    void removeNPC(const string &name);

    void removeLocation(const string &name);

    virtual string getType() const {return "Location";}
};

extern map<string, Location*> locations;