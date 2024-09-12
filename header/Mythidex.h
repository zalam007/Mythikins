#pragma once

#include <vector>
#include <string>
#include "Mythikin.h"
#include "Attack.h"
#include "Location.h"
#include "WildLocation.h"
#include "map"
#include "Item.h"
#include "NPC.h"
using namespace std;

class Mythidex
{
public:
    Mythidex();

    // |***Functions to read data from game files***|

    // Reads locations from a file and populates the locations map
    void readLocations(const string& filename);

    // Reads items from a file and populates the items map
    void readItems(const string& filename);

    // Reads NPCs from a file and populates the NPC map
    void readNPCs(const string& filename);

    // Read Mythikins from file (mythikins.txt) and adds them to allMythikins vector
    // File format: name, wild, type, level, speed, HP, attackX
    void readMythikin(const string &filename);

    // Read Moves from file (moves.txt) and adds them to allMoves vector
    // File format: name, type, power, accuracy, MM
    void readMoves(const string &filename);

    void printAllMythikinNames() const;  // Prints all Mythikin names

    void printAllMoveNames() const; // Prints all Moves names
};