#pragma once

#include "Battle.h"
#include "Mythicube.h"

class WildBattle : public Battle {
public:
    //Constructor to set team & wild Mythikin & seed
    WildBattle(Team& playerTeam, Mythikin& wildMythikin, Mythicube& myMythicube) 
        : Battle(playerTeam), wildMythikin(wildMythikin), myMythicube(myMythicube) { srand(time(0)); }

    bool isOver() override; // Override isOver to consider battle end if player team is knocked out
    bool ifWon() override;  // Override ifWon to always return false in WildBattle

    void catchMythikin();   // catch the wild Mythikin with the Mythicube
    bool Flee();    // 25% chance of fleeing
private:

    Mythikin& wildMythikin; // Wild Mythikin to battle
    Mythicube& myMythicube; // Reference to the player's Mythicube
};
