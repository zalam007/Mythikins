#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mythikin.h"
#include "header/Team.h"

class Battle {
public:
    Battle(Team& playerTeam, Team& npcTeam); // Constructor to initialize the random seed and set teams

    void stageAttack(Mythikin& attacker, Mythikin& defender, Attack& move); // Player Mythikin attacks NPC Mythikin with move
    void AIAttack(Mythikin& npcAttacker, Mythikin& playerDefender); // NPC Mythikin attacks Player Mythikin with random move
    void swapSlots(int slot1, int slot2); // Swaps the Mythikins at the given indices
    bool isOver(); // Check if the battle is over. Returns true if either team is out of Mythikins (all knocked out)
    bool ifWon(); // Check if the player has won. Returns true if the NPC team is all knocked out and the player's team is still alive
private:
    Team& playerTeam;
    Team& npcTeam;
    double getTypeAdvantage(const std::string& attackerType, const std::string& defenderType);  // Determine the attack type advantage damage multiplier
};
