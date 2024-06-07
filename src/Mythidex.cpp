#include "../header/Mythidex.h"
#include <fstream>
#include <iostream>

Mythidex::Mythidex() {}

//Read the Mythikins from the file and add them to the allMythikins vector
void Mythidex::readMythikinsFromFile(const string& filename)
{
    // Open the Mythikins file
    ifstream mythikinsFile(filename);   //txt/mythikins.txt
    
    if (!mythikinsFile) {
        cerr << "Error: Unable to open file " << filename << endl;  // Error message
        return;
    }

    string name, type;
    int level, speed, HP;
    // Read the data from the file
    while (mythikinsFile >> name >> type >> level >> speed >> HP)
    {
        if (mythikinsFile.fail()) {
            cerr << "Error: Invalid data format in file " << filename << endl;  // Error message
            return;
        }

        allMythikins.push_back(Mythikin(name, type, level, speed, HP)); // Construct Mythikin & add to the allMythikins vector
    }

    if (!mythikinsFile.eof()) {
        cerr << "Error: Failed to read the entire file " << filename << endl;   // Error message
        return;
    }

    mythikinsFile.close();
}

//Read the moves from the file and add them to the allMoves vector
void Mythidex::readMovesFromFile(const string& filename)
{
    // Open the moves file
    ifstream movesFile(filename);   //txt/moves.txt
    if (!movesFile) {
        cerr << "Error: Unable to open file " << filename << endl; // Error message
        return;
    }

    string name, type;
    int power, accuracy, MM;
    // Read the data from the file
    while (movesFile >> name >> type >> power >> accuracy >> MM)
    {
        if (movesFile.fail()) {
            cerr << "Error: Invalid data format in file " << filename << endl;  // Error message
            return;
        }

        allMoves.push_back(Attack(name, type, power, accuracy, MM));    // Construct Attack & add to the allMoves vector
    }

    if (!movesFile.eof()) {
        cerr << "Error: Failed to read the entire file " << filename << endl;   // Error message
        return;
    }

    movesFile.close();
}

//Getters
vector<Mythikin>& Mythidex::getAllMythikins() { return allMythikins; }

void Mythidex::printAllMythikinNames() const {
    for (const Mythikin& mythikin : allMythikins) {
        cout << mythikin.getName() << endl;
    }
}

vector<Attack>& Mythidex::getAllMoves() { return allMoves; }

void Mythidex::printAllMoveNames() const {
    for (const Attack& move : allMoves) {
        cout << move.getName() << endl;
    }
}