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
    // File format: name, wild, type, level, speed, HP, attackX
    void readMythikinsFromFile(const string &filename);

    // Read Moves from file (moves.txt) and adds them to allMoves vector
    // File format: name, type, power, accuracy, MM
    void readMovesFromFile(const string &filename);

    vector<Mythikin> &getAllMythikins(); // Returns allMythikins vector
    void printAllMythikinNames() const;  // Prints all Mythikin names

    vector<Attack> &getAllMoves();  // Returns allMoves vector
    void printAllMoveNames() const; // Prints all Moves names
};