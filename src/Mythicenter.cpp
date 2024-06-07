#include "../header/Mythicenter.h"

PC Mythicenter::getPC()
{
    return playerPC;
}

void Mythicenter::changePC(PC &newPC)
{
    playerPC = newPC;
}

void Mythicenter::healMythikins(vector<Mythikin> &team)
{
    for (int i = 0; i < team.size(); ++i)
    {
        team[i].setHP(team[i].getMaxHP());
    }
}