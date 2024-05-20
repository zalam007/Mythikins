#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mythikin.h"

class Battle
{
public:
    Battle() {
        // Initialize the random seed
        srand(static_cast<unsigned>(time(0)));
    }

    void stageAttack(Mythikin& attacker, Mythikin& defender, Attack& move) {
        // Check if the move has MM left
        if (move.getMM() <= 0) {
            // If no moves left, do nothing
            cout << "No moves left for " << attacker.getName() << endl;
            return;
        }

        // Decrement the MM of the move
        move.setMM(move.getMM() - 1);

        // Check the accuracy of the move
        int chance = rand() % 100;
        if (chance >= move.getAccuracy()) {
            // If the attack misses, do nothing
            cout << attacker.getName() << "'s attack missed!" << endl;
            return;
        }

        // Determine type advantage multiplier
        double typeAdvantage = getTypeAdvantage(attacker.getType(), defender.getType());

        // Calculate the damage
        int damage = static_cast<int>(move.getPower() * typeAdvantage);
    //NOTE: I THINK I CAN REMOVE ATTACKMULTIPLER

        // Reduce the defender's HP
        defender.setHP(defender.getHP() - damage);
    }

private:
    double getTypeAdvantage(const string& attackerType, const string& defenderType) {
        if ((attackerType == "fire" && defenderType == "grass") ||
            (attackerType == "grass" && defenderType == "water") ||
            (attackerType == "water" && defenderType == "fire")) {
            return 1.2;
        }
        return 1.0;
    }
};
