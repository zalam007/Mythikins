#pragma once

#include "Battle.h"
#include "Mythicube.h"

class WildBattle : public Battle {
public:
    WildBattle(Team& playerTeam, Team& npcTeam, Mythikin& wildMythikin, Mythicube& myMythicube) 
        : Battle(playerTeam, npcTeam), wildMythikin(wildMythikin), myMythicube(myMythicube) { srand(time(0)); }

    // Override isOver to consider battle end if player team is knocked out
    bool isOver() override;

    // Override ifWon to always return false in WildBattle
    bool ifWon() override;

    void tryToCatch();
    bool Flee();
    private:
    Mythikin& wildMythikin; // Wild Mythikin to battle
    Mythicube& myMythicube; // Reference to the player's Mythicube
};
