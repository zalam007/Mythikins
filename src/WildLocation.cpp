#include "../header/WildLocation.h"

int WildLocation::getSpawnRate() const
{
    return spawnRate;
}

vector<Mythikin> WildLocation::getMythikinSpawn() const
{
    return wildMythikin;
}

vector<NPC> WildLocation::getBattlerSpawn() const
{
    return battlers;
}

void WildLocation::addMythikin(const Mythikin& name)
{
    wildMythikin.push_back(name);
}

void WildLocation::removeMythikin(const string &name)
{
    for (int i = 0; i < wildMythikin.size(); ++i)
    {
        if (wildMythikin[i].getName() == name)
        {
            wildMythikin.erase(wildMythikin.begin() + i);
        }
    }
}

void WildLocation::addBattler(const NPC& name)
{
    battlers.push_back(name);
}

void WildLocation::removeBattler(const string &name)
{
    for (int i = 0; i < battlers.size(); ++i)
    {
        if (battlers[i].getName() == name)
        {
            battlers.erase(battlers.begin() + i);
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
        if (battleType <= 90)              // wild battle if battleType less than or equal to 90
        {
            cout << "You encountered a wild Mythikin!" << endl;
            Mythikin enemy = wildMythikin[rand() % wildMythikin.size()]; // pick random Mythikin to be the enemy
            WildBattleMenu wildBattle(mainCharacter, enemy, playerPC);
            wildBattle.wildGameplay();
        }
        else // trainer battle if battleType greater than 75
        {         
            cout << "You encountered a Battler!" << endl;                            
            NPC enemy = getBattlerSpawn().at(rand() % getBattlerSpawn().size()); // pick random trainer to be the enemy
            BattleMenu trainerBattle(mainCharacter, enemy);
            trainerBattle.gameplay();
        }
    }
}