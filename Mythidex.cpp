#pragma once

#include <vector>
#include <fstream>
#include "Mythikin.h"
#include "Attack.h"
#include <iostream>
using namespace std;

class Mythidex
{
private:
    vector<Mythikin> allMythikins;  // stores all Mythikins
    vector<Attack> allMoves;        // stores all moves

public:
    Mythidex() {}

    // Read Mythikins from file (mythikins.txt)
    void readMythikinsFromFile(const string& filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            string name, type;
            bool wild;
            int level, speed, HP;
            double attackX;

            while (file >> name >> boolalpha >> wild >> type >> level >> speed >> HP >> attackX)
            {
                allMythikins.push_back(Mythikin(name, wild, type, level, speed, HP, attackX));
            }

            file.close();
        }
    }

    // Read moves from file (moves.txt)
    void readMovesFromFile(const string& filename)
    {
        ifstream movesFile(filename);
        if (movesFile.is_open())
        {
            string name, type;
            int power, accuracy, MM;

            while (movesFile >> name >> type >> power >> accuracy >> MM)
            {
                allMoves.push_back(Attack(name, type, power, accuracy, MM));
            }

            movesFile.close();
        }
    }

    // Getters
    vector<Mythikin>& getAllMythikins() { return allMythikins; }

    // Print all Mythikin names
    void printAllMythikinNames() const {
        for (const Mythikin& mythikin : allMythikins) {
            cout << mythikin.getName() << endl;
        }
    }

    vector<Attack>& getAllMoves() { return allMoves; }

    // Print all Attack moves
    void getAllMoves() const {
        for (const Attack& move : allMoves) {
            cout << move.getName() << endl;
        }
    }

};