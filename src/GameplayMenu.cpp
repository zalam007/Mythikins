#include "../header/GameplayMenu.h"

GameplayMenu::GameplayMenu(Player &mainCharacter, Mythidex &mythidex) : mainCharacter(mainCharacter), mythidex(mythidex) {}

void GameplayMenu::printMenu()
{
    int command;

    while (true)
    {
        cout << "1 - Map" << endl;
        cout << "2 - Inventory" << endl;
        cout << "3 - Mythidex" << endl;
        cout << "4 - Team" << endl;
        cout << "Input: ";
        cin >> command;
        cout << endl;

        if (command == 1)
        {
            printLocations();
        }
        else if (command == 2)
        {
            viewInventory();
        }
        else if (command == 3)
        {
            viewMythidex();
        }
        else if (command == 4)
        {
            viewInventory();
        }
        else
        {
            cerr << "\nInvalid input. Try again.\n"
                 << endl;
        }
        cin.clear();
        cin.ignore();
    }
}

void GameplayMenu::printLocations()
{
    cout << "Locations" << endl;
    cout << "_________" << endl;
    for (int i = 0; i < mainCharacter.getLocation().getNeighbors().size(); ++i)
    {
        cout << i + 1 << " - " << mainCharacter.getLocation().getNeighbors()[i]->getName();
    }
    cout << "\nPress -1 to go back\n"
         << endl;
    int input;
    while (true)
    {
        cout << "Input: ";
        cin >> input;
        cout << endl;

        if (input >= 1 && input <= mainCharacter.getLocation().getNeighbors().size())
        {
            goTo(mainCharacter.getLocation().getNeighbors()[input - 1]);
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
            cout << "_________" << endl;
            for (int i = 0; i < mainCharacter.getLocation().getNeighbors().size(); ++i)
            {
                cout << i + 1 << " - " << mainCharacter.getLocation().getNeighbors()[i]->getName();
            }
            cout << "\nPress -1 to go back\n"
                 << endl;
        }
        cin.clear();
        cin.ignore();
    }
}

void GameplayMenu::goTo(Location *destination)
{
    mainCharacter.setLocation(*destination);
}

void GameplayMenu::viewInventory()
{
    cout << "Inventory" << endl;
    cout << "_________" << endl;
    cout << "Mythicoins (" << mainCharacter.getCoins() << ")" << endl
         << endl;
    for (int i = 0; i < mainCharacter.getInventory().size(); ++i)
    {
        if (mainCharacter.getInventory()[i]->getQuantity() > 0)
        {
            cout << mainCharacter.getInventory()[i]->getName() << "(x" << mainCharacter.getInventory()[i]->getQuantity() << ")" << endl;
        }
    }
}

void GameplayMenu::viewMythidex() const
{
    cout << "Mythidex" << endl;
    cout << "________" << endl;
    mythidex.printAllMythikinNames();
}

void GameplayMenu::viewTeam()
{
    cout << "Team" << endl;
    cout << "____" << endl;
    for (int i = 0; i < mainCharacter.getTeam().getSize(); ++i)
    {
        cout << i + 1 << " - " << mainCharacter.getTeam().getSlot(i).getName() << "(Lvl " << mainCharacter.getTeam().getSlot(i).getLevel();
    }
}
