using namespace std;
#include "../header/Battle.h"

//Player Mythikin attacks NPC Mythikin with move
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

//NPC Mythikin attacks Player Mythikin with random move
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

void Battle::swapSlots(int slot1, int slot2)
{
    // Check fail if the new Mythikin is knocked out
    if (playerTeam.getSlot(slot2).isKnocked()) {
      cout << "Invalid swap: Mythikin is knocked out." << endl;
      return;
    }
    playerTeam.swapSlots(slot1, slot2);
}

//Check if the battle is over
bool Battle::isOver() {
    // Check if all player's Mythikins are knocked out
    bool playerAllKnockedOut = true;
    for (int i = 0; i < playerTeam.getSize(); ++i) {
        if (playerTeam.getSlot(i).getHP() > 0) {
            playerAllKnockedOut = false;
            break;
        }
    }

    // Check if all NPC's Mythikins are knocked out
    bool npcAllKnockedOut = true;
    for (int i = 0; i < npcTeam.getSize(); ++i) {
        if (npcTeam.getSlot(i).getHP() > 0) {
            npcAllKnockedOut = false;
            break;
        }
    }

    return (playerAllKnockedOut || npcAllKnockedOut); // Return true if either team is all knocked
}

// Check if the player has won
bool Battle::ifWon() {
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

//Type advantage attack multiplier (dev note. attackX not implmented)
double Battle::getTypeAdvantage(const std::string& attackerType, const std::string& defenderType) {
    if ((attackerType == "fire" && defenderType == "grass") ||
        (attackerType == "grass" && defenderType == "water") ||
        (attackerType == "water" && defenderType == "fire")) {
        return 1.1;
    }
    return 1.0;
}
