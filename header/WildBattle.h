#pragma once

#include "Battle.h"
#include "Mythicube.h"
#include "PC.h"

class WildBattle : public Battle {
public:
    //Constructor to set Team, Wild-Mythikin & seed
    WildBattle(Team& playerTeam, Mythikin& wildMythikin, Mythicube& myMythicube) 
        : Battle(playerTeam), wildMythikin(wildMythikin), myMythicube(myMythicube) { srand(time(0)); }

    bool isOver() override; // True if the player's team is all knocked out, or the wild Mythikin is knocked out or caught
    bool ifWon() override;  // True if isOver is true and the player has at least one Mythikin alive or caught the wild Mythikin

    void catchMythikin(PC& playerPC);   // catch the wild Mythikin with the Mythicube (store in team, if full in PC)
    bool Flee();    // 10% chance of fleeing (returnig true)
private:
    Mythikin& wildMythikin; // Wild-Mythikin to battle
    Mythicube& myMythicube; // Reference to the player's Mythicube
};
