#pragma once
#include "Mythikin.h"
#include "PC.h"
#include "Location.h"

class Mythicenter : protected Location
{
private:
    PC playerPC;

public:
    Mythicenter(const string &name, const vector<Location *> &neighbors, const PC &playerPC) : Location(name, neighbors), PC(playerPC) {}

    Mythicenter(const string &name, const vector<Location *> &neighbors, const vector<NPC> &npcs, const PC &playerPC) : Location(name, neighbors, npcs), PC(playerPC) {}

    PC getPC();

    void changePC(PC &newPC);

    void healMythikins(const vector<Mythikin> &team);
};
