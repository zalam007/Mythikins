#include "../header/WildBattle.h"

bool WildBattle::isOver() {
    // Return true if the wild Mythikin was successfully caught
    if (isCaught)
        return true;
    
    // Check if all player's Mythikins are knocked out
    // bool playerAllKnockedOut = true;
    // for (int i = 0; i < playerTeam.getSize(); i++) {
    //     cout << "team size: "<< playerTeam.getSize() << endl;
    //     if (playerTeam.getSlot(i).getHP() > 0) {
    //         cout << playerTeam.getSlot(i).getName() << " is alive" << endl;
    //         cout << "Value of i: " << i << endl;
    //         playerAllKnockedOut = false;
    //     }
    // }

    // Check if the wild Mythikin is knocked out
    // bool npcKnockedOut = true;
    if (wildMythikin.isKnocked()) {
        return true;
    }

    for (int i = 0; i < playerTeam.getSize(); i++) {
        if (playerTeam.getSlot(i).getHP() > 0) {
            return false;
        }
    }

    return true;

    // return playerAllKnockedOut || npcKnockedOut; // Return true if either party is all knocked
}

bool WildBattle::ifWon() {
    // Return true if the wild Mythikin was successfully caught
    if (isCaught)
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

//Add Mythikin to player's team if caught, if the team is full add the Mythikin to the PC
bool WildBattle::catchMythikin(PC& playerPC, Mythicube& myMythicube) {
    myMythicube.use(wildMythikin); // Call the use method of Mythicube to attempt catching the wild Mythikin
    Mythikin* capturedMythikin = myMythicube.getCapturedMythikin(); // Get the captured Mythikin (nullptr if not caught)

    if (capturedMythikin != nullptr) { // Check if the Mythikin was successfully caught
        capturedMythikin->setWild(false); // Set the Mythikin to be tamed 
        isCaught=true; // Set the isCaught flag to true
        // Add the Mythikin to the player's team if there's space
        if (playerTeam.getSize() < playerTeam.getMaxSize()) {
            playerTeam.addMythikin(*capturedMythikin);
        } 
        // Add the Mythikin to the PC if the team is full
        else {
            playerPC.placeMythikinToPC(*capturedMythikin);
        }
        myMythicube.emptyMythicube(); // Empty the Mythicube after adding the Mythikin to the team or PC
        return true;
    }
    return false;
}

// 10% chance of fleeing
bool WildBattle::Flee() {
    int randomNum = rand() % 10; // Generate a random number between 0 and 9
    return randomNum <= 3; // If the random number is 0, return true (10% chance of fleeing)
}