#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mythikin.h"
#include "header/Team.h"

class Battle {
public:
    Battle(); // Constructor to initialize the random seed

    void stageAttack(Mythikin& attacker, Mythikin& defender, Attack& move); // Player Mythikin attacks NPC Mythikin with move
    void AIAttack(Mythikin& npcAttacker, Mythikin& playerDefender); // NPC Mythikin attacks Player Mythikin with random move
private:
    double getTypeAdvantage(const std::string& attackerType, const std::string& defenderType);  // Determine the attack type advantage damage multiplier
};
