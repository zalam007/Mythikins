#include "../header/Mythicenter.h"

PC* Mythicenter::getPC()
{
    return playerPC;
}

void Mythicenter::changePC(PC &newPC)
{
    playerPC = &newPC;
}

void Mythicenter::healMythikins(Team &team)
{
    for (int i = 0; i < team.getSize(); ++i)
    {
        team.getSlot(i).setHP(team.getSlot(i).getMaxHP());
    }
}