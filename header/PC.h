#pragma once

#include <vector>
#include "../header/Mythikin.h"
#include "../header/Player.h"
#include "../header/Team.h"
using namespace std;

class PC
{
    vector<Mythikin *> mythikinPCStorage; // Empty list of Mythikin in the PC. Stores all Mythikin the Player has caught.

public:
    // Constructor needs no parameters.

    ~PC(); // Destructor deletes all Mythikin in the PC.

    const vector<Mythikin *> getPCList() const { return mythikinPCStorage; } // Returns the list of Mythikin that are in the PC.

    void depositMythikin(Mythikin &mover, Team &userTeam); // Place a Mythikin into the PC and remove it from the team

    void withdrawMythikin(const string name, Team &userTeam); // Place a Mythikin into the Team and remove it from the PC

    void placeMythikinToPC(Mythikin &mover); // Place a Mythikin into the PC without looking at the team
};