#include "../header/PC.h"

void PC::depositMythikin(Mythikin &mover)
{
    if (user->getTeam().getSize() > 1)
    {                                                     // Only able to deposit as long as there is more than one Mythikin in the team.
        mythikinPCStorage.push_back(new Mythikin(mover)); // Adds a new Mythikin to the PC.
        user->getTeam().removeMythikin(mover.getName());  // Removes the Mythikin from the team.
    }
    // Nothing if the team is empty or only has one Mythikin.
}

void PC::withdrawMythikin(const string name)
{
    if (user->getTeam().getSize() <= user->getTeam().getMaxSize())
    {                                                      // Only able to withdraw as long as the team is not full.
        for (int i = 0; i < mythikinPCStorage.size(); ++i) // Iterates through the PC storage.
        {
            if (mythikinPCStorage[i]->getName() == name) // If found the Mythikin by its name
            {
                user->getTeam().addMythikin(*mythikinPCStorage[i]);     // Adds the Mythikin to the team.
                mythikinPCStorage.erase(mythikinPCStorage.begin() + i); // Removes the Mythikin from the PC.
            }
        }
        // Nothing if the Mythikin is not found.
    }
    // Nothing if the team is full.
}