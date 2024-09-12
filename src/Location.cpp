#include "../header/Location.h"

void Location::removeNPC(const string &name)
{
    for (int i = 0; i < NPCSpawn.size(); ++i)
    {
        if (NPCSpawn[i]->getName() == name)
        {
            NPCSpawn.erase(NPCSpawn.begin() + i);
        }
    }
}

void Location::removeLocation(const string &name)
{
    for (int i = 0; i < neighborLocations.size(); ++i)
    {
        if (neighborLocations[i]->getName() == name)
        {
            delete neighborLocations[i];
            neighborLocations.erase(neighborLocations.begin() + i);
        }
    }
}