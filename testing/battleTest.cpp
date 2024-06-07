using namespace std;
#include <iostream>
#include "header/Battle.h"
#include "header/Mythikin.h"
#include "header/Attack.h"
#include "header/Team.h"
//g++ src/battleTest.cpp src/Battle.cpp src/Team.cpp

int main() {
    // Create player Mythikins
    Mythikin player1("FireDragon", false, "fire", 10, 30, 100, 1.2);
    player1.addAttack(Attack("FlameThrower", "fire", 40, 90, 10));
    player1.addAttack(Attack("FireBlast", "fire", 50, 85, 5));

    Mythikin player2("WaterSplash", false, "water", 8, 25, 90, 1.1);
    player2.addAttack(Attack("WaterGun", "water", 30, 95, 15));
    player2.addAttack(Attack("AquaJet", "water", 35, 90, 10));

    // Create NPC Mythikins
    Mythikin npc1("GrassBeast", true, "grass", 9, 28, 95, 1.15);
    npc1.addAttack(Attack("VineWhip", "grass", 35, 90, 10));
    npc1.addAttack(Attack("LeafStorm", "grass", 45, 80, 5));

    Mythikin npc2("RockGolem", true, "rock", 7, 20, 110, 1.0);
    npc2.addAttack(Attack("RockThrow", "rock", 40, 85, 10));
    npc2.addAttack(Attack("StoneEdge", "rock", 50, 80, 5));

    // Create teams
    Team playerTeam;
    playerTeam.addMythikin(player1);
    playerTeam.addMythikin(player2);

    Team npcTeam;
    npcTeam.addMythikin(npc1);
    npcTeam.addMythikin(npc2);

    // Start the battle
    Battle battle(playerTeam, npcTeam);

    // Simulate battle loop
    while (!battle.isOver()) {
        // Player's turn
        for (int i = 0; i < playerTeam.getSize(); ++i) {
            if (!playerTeam.getSlot(i).isKnocked()) {
                // Find the first NPC Mythikin that is not knocked out
                for (int j = 0; j < npcTeam.getSize(); ++j) {
                    if (!npcTeam.getSlot(j).isKnocked()) {
                        // Use the first attack available
                        if (!playerTeam.getSlot(i).getAttacks().empty()) {
                            battle.stageAttack(playerTeam.getSlot(i), npcTeam.getSlot(j), playerTeam.getSlot(i).getAttacks().at(0));
                        }
                        break;
                    }
                }
            }
        }

        // Check if the battle is over
        if (battle.isOver()) {
            break;
        }

        // NPC's turn
        for (int i = 0; i < npcTeam.getSize(); ++i) {
            if (!npcTeam.getSlot(i).isKnocked()) {
                // Find the first player Mythikin that is not knocked out
                for (int j = 0; j < playerTeam.getSize(); ++j) {
                    if (!playerTeam.getSlot(j).isKnocked()) {
                        battle.AIAttack(npcTeam.getSlot(i), playerTeam.getSlot(j));
                        break;
                    }
                }
            }
        }

        // Check if the battle is over
        if (battle.isOver()) {
            break;
        }
    }

    // Check if the player won
    if (battle.ifWon()) {
        cout << "Player wins the battle!" << endl;
    } else {
        cout << "NPC wins the battle!" << endl;
    }

    return 0;
}
