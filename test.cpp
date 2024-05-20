using namespace std;
#include <iostream>
#include "Battle.h"

int main() {
    // Create some attacks
    Attack fireBlast("Fire Blast", "fire", 100, 85, 5);
    Attack waterGun("Water Gun", "water", 40, 100, 25);
    Attack vineWhip("Vine Whip", "grass", 45, 100, 15);

    // Create two Mythikin creatures
    Mythikin charmander("Charmander", false, "fire", 5, 65, 200, 1.1);
    Mythikin bulbasaur("Bulbasaur", true, "grass", 5, 45, 220, 1.1);

    // Add attacks to Mythikins
    charmander.addAttack(fireBlast);
    charmander.addAttack(vineWhip);
    bulbasaur.addAttack(waterGun);
    bulbasaur.addAttack(vineWhip);

    // Create a battle
    Battle battle;

    // Simulate a battle round where Charmander attacks Bulbasaur with Fire Blast
    cout << "Charmander attacks Bulbasaur with Fire Blast!" << endl;
    battle.stageAttack(charmander, bulbasaur, fireBlast);

    // Display the results
    cout << "Bulbasaur's HP after attack: " << bulbasaur.getHP() << "/" << bulbasaur.getMaxHP() << endl;

    // Check if Bulbasaur is knocked out
    if (bulbasaur.isKnocked()) {
        cout << "Bulbasaur is knocked out!" << endl;
    } else {
        cout << "Bulbasaur survives the attack." << endl;
    }

    // Simulate a battle round where Bulbasaur attacks Charmander with Water Gun
    cout << "Bulbasaur attacks Charmander with Water Gun!" << endl;
    battle.stageAttack(bulbasaur, charmander, waterGun);

    // Display the results
    cout << "Charmander's HP after attack: " << charmander.getHP() << "/" << charmander.getMaxHP() << endl;

    // Check if Charmander is knocked out
    if (charmander.isKnocked()) {
        cout << "Charmander is knocked out!" << endl;
    } else {
        cout << "Charmander survives the attack." << endl;
    }

    return 0;
}
