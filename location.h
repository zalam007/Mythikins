#pragma once

#include <vector>
#include "mythikin.h"
using namespace std;

class Location {
private:
    string name;
    vector<Mythikin> MythikinSpawn;
public:
    Location(const string& name, const vector <Mythikin>& Mythikins) : name(name), MythikinSpawn(Mythikins) {}

    string getName() {
        return name;
    }

    void setMythikins(const vector <Mythikin>& Mythikins) {
        MythikinSpawn = Mythikins;
    }
};