#pragma once

#include <vector>
#include "../header/Mythikin.h"
#include "../header/Player.h"
#include "../header/Team.h"
using namespace std;

class PC
{
    Player *user;                         // Pointer to user to access their team
    vector<Mythikin *> mythikinPCStorage; // Empty list of Mythikin in the PC. Stores all Mythikin the Player has caught.

public:
    // Needs a player in order to access the team. NO PC without a player.
    PC(Player *playerUser) : user(playerUser) {}

    ~PC()
    { // Deletes entire PC storage.
        for (int i = 0; i < mythikinPCStorage.size(); ++i)
        {
            delete mythikinPCStorage[i]; // Each deposited mythikin in the PC is deleted.
        }
        delete user; // User is deleted from PC.
    }

    const vector<Mythikin *> getPCList() const { return mythikinPCStorage; } // Returns the list of Mythikin that are in the PC.

    void depositMythikin(Mythikin &mover); // To place a Mythikin from the PC into the user's team.

    void withdrawMythikin(const string name); // To take a Mythikin from the PC and place it in the user's team.
};