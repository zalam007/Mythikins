#include "Battle.h"

using namespace std;

Battle::Battle() {
    srand(static_cast<unsigned>(time(0))); // Initialize the random seed
}

void Battle::stageAttack(Mythikin& attacker, Mythikin& defender, Attack& move) {
    // Check if the attacker move has any moves left
    if (move.getMM() <= 0) {
        cout << attacker.getName() << " has no moves left for " << move.getName() << "!" << endl;
        return; // If no moves left, do nothing
    }

    move.setMM(move.getMM() - 1); // Decrement the MM of the move

    // Check the accuracy of the move
    int chance = rand() % 100;
    if (chance >= move.getAccuracy()) {
        cout << attacker.getName() << "'s attack missed!" << endl;
        return; // If the attack misses, do nothing
    }

    // Determine type advantage multiplier
    double typeAdvantage = getTypeAdvantage(attacker.getType(), defender.getType());
    // Calculate the damage
    int damage = static_cast<int>(move.getPower() * typeAdvantage);
    // Reduce the defender's HP
    defender.setHP(defender.getHP() - damage);
    cout << attacker.getName() << " used " << move.getName() << " and dealt " << damage << " damage!" << endl;
}

void Battle::AIAttack(Mythikin& npcAttacker, Mythikin& playerDefender) {
    // Get the NPC's available attacks
    vector<Attack> availableAttacks = npcAttacker.getAttacks();
    if (availableAttacks.empty()) {
        cout << npcAttacker.getName() << " has no moves left!" << endl;
        return;
    }

    // Randomly select one of the attacks
    int moveIndex = rand() % availableAttacks.size();
    Attack& move = availableAttacks[moveIndex];

    // Check if the move has MM left
    if (move.getMM() <= 0) {
        cout << npcAttacker.getName() << " has no moves left for " << move.getName() << "!" << endl;
        return;
    }

    // Decrement the MM of the move
    move.setMM(move.getMM() - 1);

    // Check the accuracy of the move
    int chance = rand() % 100;
    if (chance >= move.getAccuracy()) {
        cout << npcAttacker.getName() << "'s attack missed!" << endl;
        return;
    }

    // Determine type advantage multiplier
    double typeAdvantage = getTypeAdvantage(npcAttacker.getType(), playerDefender.getType());

    // Calculate the damage
    int damage = static_cast<int>(move.getPower() * typeAdvantage);

    // Reduce the player's HP
    playerDefender.setHP(playerDefender.getHP() - damage);
    cout << npcAttacker.getName() << " used " << move.getName() << " and dealt " << damage << " damage!" << endl;
}

void Battle::swap(Mythikin& currentMythikin, Team& team, int newMythikinIndex) {
    // Check if new index is within the bounds of the team
    if (newMythikinIndex < 0 || newMythikinIndex >= team.getSize()) {
        cerr << "Invalid swap: Index out of bounds." << endl;
        return;
    }

    // Check if the new Mythikin is knocked out
    Mythikin& newMythikin = team.getSlot(newMythikinIndex);
    if (newMythikin.isKnocked()) {
        cout << "Invalid swap: Mythikin is knocked out." << endl;
        return;
    }

    // Perform the swap
    Mythikin oldMythikin = currentMythikin;
    currentMythikin = newMythikin;
    newMythikin = oldMythikin;

    cout << "Swapped " << currentMythikin.getName() << " with " << newMythikin.getName() << "." << endl;
}

double Battle::getTypeAdvantage(const std::string& attackerType, const std::string& defenderType) {
    if ((attackerType == "fire" && defenderType == "grass") ||
        (attackerType == "grass" && defenderType == "water") ||
        (attackerType == "water" && defenderType == "fire")) {
        return 1.1;
    }
    return 1.0;
}
