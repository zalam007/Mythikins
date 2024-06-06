#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mythikin.h"   // Attack.h included
#include "Team.h"

class Battle {
public:
    //Constructor to initialize the random seed and set teams
    Battle(Team& playerTeam, Team& npcTeam) : playerTeam(playerTeam), npcTeam(npcTeam) { srand(time(0)); }
    Battle(Team& playerTeam) : playerTeam(playerTeam) { srand(time(0)); }   // Constructor for WildBattle inheritance

    void stageAttack(Mythikin& attacker, Mythikin& defender, Attack& move); // Player Mythikin attacks NPC Mythikin with move
    void AIAttack(Mythikin& npcAttacker, Mythikin& playerDefender); // NPC Mythikin attacks Player Mythikin with random move
    void swapSlots(int slot1, int slot2); // Swaps the Mythikins in the team array at the given indices if the Mythikin at slot2 is alive
    virtual bool isOver(); // Check if the battle is over. Returns true if either team is out of Mythikins (all knocked out)
    virtual bool ifWon(); // Check if the player has won. Returns true if the NPC team is all knocked out and the player's team is still alive
protected:
    Team& playerTeam;
    Team npcTeam; // Todo: This needs to be a reference type
    double getTypeAdvantage(const std::string& attackerType, const std::string& defenderType);  // Determine the attack type advantage damage multiplier
};
