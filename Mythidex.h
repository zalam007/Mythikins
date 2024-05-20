#pragma once

#include <vector>
#include <string>
#include "Mythikin.h"
#include "Attack.h"
using namespace std;

class Mythidex
{
private:
    vector<Mythikin> allMythikins;
    vector<Attack> allMoves;

public:
    Mythidex();

    // Read Mythikins from file (mythikins.txt) and adds them to allMythikins vector
    void readMythikinsFromFile(const string& filename);
    // Read Moves from file (moves.txt) and adds them to allMoves vector
    void readMovesFromFile(const string& filename);

    vector<Mythikin>& getAllMythikins();
    void printAllMythikinNames() const;

    vector<Attack>& getAllMoves();
    void printAllMoves() const;
};