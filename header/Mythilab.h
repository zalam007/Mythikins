#include "Location.h"
#include "Mythikin.h"

class Mythilab : protected Location
{
private:
    vector<Mythikin> starters;

public:
    Mythilab(const string &name, const vector<Location *> &neighbors, vector<Mythikin> mythikinList) : Location(name, neighbors), starters(mythikinList) {}

    Mythilab(const string &name, const vector<Location *> &neighbors, const vector<NPC> &npcs, vector<Mythikin> mythikinList) : Location(name, neighbors, npcs), starters(mythikinList) {}

    Mythikin getMythikin(int index)
    {
        return starters[index];
    }

    vector<Mythikin> getStarters()
    {
        return starters;
    }
};