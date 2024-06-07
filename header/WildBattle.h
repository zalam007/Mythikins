#pragma once

#include "Battle.h"
#include "Mythicube.h"
#include "PC.h"

class WildBattle : public Battle {
public:
    //Constructor to set Team, Wild-Mythikin & seed
    WildBattle(Team& playerTeam, Mythikin& wildMythikin) 
        : Battle(playerTeam), wildMythikin(wildMythikin) { srand(time(0)); }

    bool isOver() override; // True if the player's team is all knocked out, or the wild Mythikin is knocked out or caught
    bool ifWon() override;  // True if isOver is true and the player has at least one Mythikin alive or caught the wild Mythikin

    void catchMythikin(PC& playerPC, Mythicube& myMythicube);   // catch the wild Mythikin with the Mythicube (store in team, if full in PC)
    bool Flee();    // 10% chance of fleeing (returnig true)
private:
    bool isCaught;    // Sees if the Mythicube was successful
    Mythikin& wildMythikin; // Wild-Mythikin to battle
};
