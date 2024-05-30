#include "../header/Mythidex.h"
#include <fstream>
#include <iostream>

Mythidex::Mythidex() {}

void Mythidex::readMythikinsFromFile(const string& filename)
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

void Mythidex::readMovesFromFile(const string& filename)
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

vector<Mythikin>& Mythidex::getAllMythikins() { return allMythikins; }

void Mythidex::printAllMythikinNames() const {
    for (const Mythikin& mythikin : allMythikins) {
        cout << mythikin.getName() << endl;
    }
}

vector<Attack>& Mythidex::getAllMoves() { return allMoves; }

void Mythidex::printAllMoves() const {
    for (const Attack& move : allMoves) {
        cout << move.getName() << endl;
    }
}