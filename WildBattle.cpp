#include "WildBattle.h"

bool WildBattle::isOver() {
    // Call the base class isOver() to check if player's team is knocked out
    if (Battle::isOver())
        return true;

    // Check if the wild Mythikin was successfully caught
    if (myMythicube.getCapturedMythikin() != nullptr)
        return true;

    return false;
}

bool WildBattle::ifWon() {
    // Call the base class ifWon() to check if the player won the battle normally
    if (Battle::ifWon())
        return true;

    // Check if the wild Mythikin was successfully caught
    if (myMythicube.getCapturedMythikin() != nullptr)
        return true;

    return false;
}

void WildBattle::tryToCatch() {
    myMythicube.use(wildMythikin); // Call the use method of Mythicube to attempt catching the wild Mythikin
}

bool WildBattle::Flee() {
    // Generate a random number between 0 and 3
    int randomNum = rand() % 4;

    // If the random number is 0, return true (25% chance of fleeing)
    return randomNum == 0;
}