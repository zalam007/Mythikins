#include "../header/WildLocation.h"

int WildLocation::getSpawnRate() const
{
    return spawnRate;
}

vector<Mythikin> WildLocation::getMythikinSpawn() const
{
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

void WildLocation::encounter(Player &mainCharacter, PC &playerPC) const
{
    srand(time(0));                   // use current time as seed
    int encounter = rand() % 100 + 1; // random number between 1 and 100 used determine if enemy spawns

    if (encounter <= spawnRate) // encounter enemy if random number is less than or equal to the spawnrate
    {
        int battleType = rand() % 100 + 1; // random number between 1 and 100 used to determine if the battle is a trainer or wild battle
        if (battleType <= 75)              // wild battle if battleType less than or equal to 75
        {
            Mythikin enemy = mythikinSpawn[rand() % mythikinSpawn.size()]; // pick random Mythikin to be the enemy
            WildBattleMenu wildBattle(mainCharacter, enemy, playerPC);
            wildBattle.wildGameplay();
        }
        else // trainer battle if battleType greater than 75
        {                                                   
            NPC enemy = getNPCList()[rand() % getNPCList().size()]; // pick random trainer to be the enemy
            BattleMenu trainerBattle(mainCharacter, enemy);
            trainerBattle.gameplay();
        }
    }
}