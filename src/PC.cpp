#include "../header/PC.h"

PC::~PC() // Deletes entire PC storage.
{
    for (int i = 0; i < mythikinPCStorage.size(); ++i)
    {
        delete mythikinPCStorage[i]; // Each deposited mythikin in the PC is deleted.
    }
}

void PC::depositMythikin(Mythikin &mover, Team &userTeam)
{
    if (userTeam.getSize() > 1)
    {                                                     // Only able to deposit as long as there is more than one Mythikin in the team.
        mythikinPCStorage.push_back(new Mythikin(mover)); // Adds a new Mythikin to the PC.
        userTeam.removeMythikin(mover.getName());         // Removes the Mythikin from the team.
        return;
    }
    // Nothing if the team is empty or only has one Mythikin.
    cerr << "You can not deposit your one Mythikin in your team!" << endl;
}

void PC::withdrawMythikin(const string name, Team &userTeam)
{
    if (userTeam.getSize() <= userTeam.getMaxSize())
    {                                                      // Only able to withdraw as long as the team is not full.
        for (int i = 0; i < mythikinPCStorage.size(); ++i) // Iterates through the PC storage.
        {
            if (mythikinPCStorage[i]->getName() == name) // If found the Mythikin by its name
            {
                userTeam.addMythikin(*mythikinPCStorage[i]);            // Adds the Mythikin to the team.
                mythikinPCStorage.erase(mythikinPCStorage.begin() + i); // Removes the Mythikin from the PC.
                return;
            }
        }
        // Nothing if the Mythikin is not found.
        cerr << "Mythikin not found!" << endl;
        return;
    }
    // Nothing if the team is full.
    cerr << "Team is full. No space to withdraw from PC into your team!" << endl;
}

void PC::placeMythikinToPC(Mythikin &mover)
{
    mythikinPCStorage.push_back(new Mythikin(mover)); // Adds a new Mythikin to the PC.
}