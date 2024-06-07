#include "../header/WildLocation.h"

int WildLocation::getSpawnRate() const
{
    return spawnRate;
}

vector<Mythikin> WildLocation::getMythikinSpawn() const {
    return mythikinSpawn;
}

void WildLocation::addMythikin(const Mythikin &name)
{
    mythikinSpawn.push_back(name);
}

void WildLocation::removeMythikin(const string &name)
{
    for (int i = 0; i < mythikinSpawn.size(); ++i)
    {
        if (mythikinSpawn[i].getName() == name)
        {
            mythikinSpawn.erase(mythikinSpawn.begin() + i);
        }
    }
}

void WildLocation::setSpawnRate(int spawnRate)
{
    this->spawnRate = spawnRate;
}

void WildLocation::encounter() const
{
    // do later
}