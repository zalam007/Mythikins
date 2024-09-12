#include "../header/GameplayMenu.h"
#include <thread>
#include <chrono>

GameplayMenu::GameplayMenu(Player &mainCharacter, Mythidex &mythidex) : mainCharacter(mainCharacter), mythidex(mythidex) {}

void GameplayMenu::printMenu() {
    int command;

    while (true) {
        cout << "Open World Menu" << endl;
        cout << "1 - Map" << endl;
        cout << "2 - Inventory" << endl;
        cout << "3 - Mythidex" << endl;
        cout << "4 - Team" << endl;
        cout << "5 - Interact" << endl;
        cout << "6 - EXIT GAME" << endl;
        cout << "Input: ";
        cin >> command;

        if (cin.fail()) {
            // Clear error flags, discard invalid input, and continue loop
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\nInvalid input. Please enter a number.\n" << endl;
            continue;
        }

        cout << endl << endl;

        // Handle valid commands
        if (command == 1) {
            printLocations();
            break;  // Exit the menu loop and return to main loop
        }
        else if (command == 2) {
            viewInventory();
            break;  // Exit the menu loop and return to main loop
        }
        else if (command == 3) {
            viewMythidex();
            break;  // Exit the menu loop and return to main loop
        }
        else if (command == 4) {
            viewTeam();
            break;  // Exit the menu loop and return to main loop
        }
        else if (command == 5) {
            viewNPCs();
            break;  // Exit the menu loop and return to main loop
        }
        else if (command == 6) {
            cout << "Exiting game..." << endl;
            exit(0);
        }
        else {
            cerr << "\nInvalid input. Please choose a valid option (1-6).\n" << endl;
        }

        // Clear any potential leftover input after each command processing
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


void GameplayMenu::printLocations()
{
    cout << "Locations" << endl;
    cout << "---------" << endl;
    for (int i = 0; i < mainCharacter.getLocation()->getNeighbors().size(); ++i)
    {
        cout << i + 1 << " - " << mainCharacter.getLocation()->getNeighbors()[i]->getName() << endl << endl;
    }
    cout << "\nPress -1 to go back\n"
         << endl << endl;
    int input;
    while (true)
    {
        cout << "Input: ";
        cin >> input;
        cout << endl;

        if (input >= 1 && input <= mainCharacter.getLocation()->getNeighbors().size())
        {
            goTo(mainCharacter.getLocation()->getNeighbors()[input - 1]);
            return;
        }
        else if (input == -1)
        {
            return;
        }
        else
        {
            cerr << "\nInvalid input. Try again.\n"
                 << endl;
            cout << "Locations" << endl;
            cout << "---------" << endl;
            for (int i = 0; i < mainCharacter.getLocation()->getNeighbors().size(); ++i)
            {
                cout << i + 1 << " - " << mainCharacter.getLocation()->getNeighbors()[i]->getName() << endl << endl;
            }
            cout << "\nPress -1 to go back\n"
                 << endl << endl;
        }
        cin.clear();
        cin.ignore();
    }
}

void GameplayMenu::goTo(Location* destination)
{
    cout << "Traveling to " << destination->getName() << "..." << endl << endl;
    mainCharacter.setLocation(destination);
}

void GameplayMenu::viewInventory()
{
    cout << "Inventory" << endl;
    cout << "---------" << endl;
    cout << "Mythicoins (" << mainCharacter.getCoins() << ")" << endl
         << endl;

    if(mainCharacter.getItemInventory().size() == 0 && mainCharacter.getBattleInventory().size() == 0){
        cout << "Your inventory is empty!" << endl << endl;
        return;
    }

    for (int i = 0; i < mainCharacter.getItemInventory().size(); ++i) // All non-usable items
    {
        if (mainCharacter.getItemInventory()[i]->getQuantity() > 0)
        {
            cout << mainCharacter.getItemInventory()[i]->getName() << "(x" << mainCharacter.getItemInventory()[i]->getQuantity() << ")" << endl << endl;
        }
    }

    for (int i = 0; i < mainCharacter.getBattleInventory().size(); ++i) // all battle items
    {
        if (mainCharacter.getBattleInventory()[i]->getQuantity() > 0)
        {
            cout << mainCharacter.getBattleInventory()[i]->getName() << "(x" << mainCharacter.getBattleInventory()[i]->getQuantity() << ")" << endl << endl;
        }
    }
}

void GameplayMenu::viewMythidex() const
{
    cout << "Mythidex" << endl;
    cout << "--------" << endl;
    mythidex.printAllMythikinNames();
    cout << endl;
}

void GameplayMenu::viewTeam()
{
    cout << "Team" << endl;
    cout << "----" << endl;
    if(mainCharacter.getTeam().getSize() == 0){
        cout << "Your team is empty!" << endl << endl;
        return;
    }
    else {
        for (int i = 0; i < mainCharacter.getTeam().getSize(); ++i)
        {
            cout << i + 1 << " - " << mainCharacter.getTeam().getSlot(i).getName() << "(Lvl " << mainCharacter.getTeam().getSlot(i).getLevel() << ")" << endl << endl;
        }
    }

}

void GameplayMenu::viewNPCs() {
    cout << "NPCs" << endl;
    cout << "----" << endl;
    if(mainCharacter.getLocation()->getNPCList().size() == 0){
        cout << "There are no people to talk to here!" << endl << endl;
        return;
    }
    else {
        // Display the list of NPCs at the current location
        for (int i = 0; i < mainCharacter.getLocation()->getNPCList().size(); ++i) {
            cout << i + 1 << " - " << mainCharacter.getLocation()->getNPCList()[i]->getName() << endl << endl;
        }
    }


    cout << "\nPress -1 to go back\n" << endl << endl;

    int input;
    while (true) {
        cout << "Input: ";
        cin >> input;
        cout << endl;

        // If the user selects a valid NPC from the list
        if (input >= 1 && input <= mainCharacter.getLocation()->getNPCList().size()) {
            // Get the selected NPC and have it talk
            NPC* selectedNPC = mainCharacter.getLocation()->getNPCList()[input - 1];
            cout << selectedNPC->getName() << ": " << selectedNPC->talk() << endl << endl;  // Display the NPC's dialogue
            return;
        }
        else if (input == -1) {
            return;  // Go back to the previous menu
        }
        else {
            // If input is invalid, display an error message and re-show the NPC list
            cerr << "\nInvalid input. Try again.\n" << endl;

            cout << "NPCs" << endl;
            cout << "----" << endl;
            for (int i = 0; i < mainCharacter.getLocation()->getNPCList().size(); ++i) {
                cout << i + 1 << " - " << mainCharacter.getLocation()->getNPCList()[i]->getName() << endl << endl;
            }
            cout << "\nPress -1 to go back\n" << endl << endl;
        }

        // Clear the input buffer in case of invalid input
        cin.clear();
        cin.ignore();
    }
}
