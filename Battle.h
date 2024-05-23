#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mythikin.h"
#include "header/Team.h"

class Battle {
public:
    Battle(); // Constructor to initialize the random seed

    void stageAttack(Mythikin& attacker, Mythikin& defender, Attack& move); // Player Mythikin attacks NPC Mythikin
    void AIAttack(Mythikin& npcAttacker, Mythikin& playerDefender); // NPC Mythikin attacks Player Mythikin
    void swap(Mythikin& currentMythikin, Team& team, int newMythikinIndex); // Swap Mythikins in the team

private:
    double getTypeAdvantage(const std::string& attackerType, const std::string& defenderType);  // Determine the attack type advantage multiplier
};
