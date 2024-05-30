#include "../header/WildBattle.h"

bool WildBattle::isOver() {
    // Return true if the wild Mythikin was successfully caught
    if (myMythicube.getCapturedMythikin() != nullptr)
        return true;
    
    // Check if all player's Mythikins are knocked out
    bool playerAllKnockedOut = true;
    for (int i = 0; i < Battle::playerTeam.getSize(); ++i) {
        if (Battle::playerTeam.getSlot(i).getHP() > 0) {
            playerAllKnockedOut = false;
            break;
        }
    }

    // Check if the wild Mythikin is knocked out
    bool npcKnockedOut = true;
    if (wildMythikin.getHP() <= 0)
        npcKnockedOut = false;

    return playerAllKnockedOut || npcKnockedOut; // Return true if either party is all knocked
}

bool WildBattle::ifWon() {
    // Return true if the wild Mythikin was successfully caught
    if (myMythicube.getCapturedMythikin() != nullptr)
        return true;

    // Check if any player's Mythikins are still alive
    bool playerHasAlive = false;
    for (int n = 0; n < playerTeam.getSize(); n++) {
        if (playerTeam.getSlot(n).getHP() > 0) {
            playerHasAlive = true;
            break;
        }
    }

    return isOver() && playerHasAlive;
}


void WildBattle::catchMythikin() {
    myMythicube.use(wildMythikin); // Call the use method of Mythicube to attempt catching the wild Mythikin
}

// 25% chance of fleeing
bool WildBattle::Flee() {
    int randomNum = rand() % 4; // Generate a random number between 0 and 3
    return randomNum == 0; // If the random number is 0, return true (25% chance of fleeing)
}