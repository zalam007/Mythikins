#pragma once
#include "Mythikin.h"
#include "PC.h"
#include "Location.h"

class Mythicenter : public Location
{
private:
    PC* playerPC;

public:
    Mythicenter(const string &name) : Location(name), playerPC(playerPC) {}

    Mythicenter(const string &name, const vector<Location *> &neighbors, PC* playerPC) : Location(name, neighbors), playerPC(playerPC) {}

    Mythicenter(const string &name, const vector<Location *> &neighbors, vector<NPC*> &npcs, PC* playerPC) : Location(name, neighbors, npcs), playerPC(playerPC) {}

    PC* getPC();

    void changePC(PC &newPC);

    void healMythikins(Team& team);

    string getType() const{
        return "Mythicenter";
    }
};
