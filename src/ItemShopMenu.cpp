#include "../header/ItemShopMenu.h"

void ItemShopMenu::printMenu(Mythishop &shop, Player &shopper)
{
    int command;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Welcome to the Mythishop! What service are you looking for?\n\n"
         << endl;
    cout << "1. Buy" << endl;
    cout << "2. Sell" << endl;
    cout << "3. Leave\n"
         << endl;

    while (true)
    {
        cin >> command;
        cout << endl;

        if (command == 1)
        {
            buyMenu(shop, shopper);
            cout << "Anything else?" << endl;
            cout << "1. Buy" << endl;
            cout << "2. Sell" << endl;
            cout << "3. Leave\n"
                 << endl;
        }
        else if (command == 2)
        {
            sellMenu(shopper);
            cout << "Anything else?" << endl;
            cout << "1. Buy" << endl;
            cout << "2. Sell" << endl;
            cout << "3. Leave\n"
                 << endl;
        }
        else if (command == 3)
        {
            cout << "\nCome again!" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        }
        else
        {
            cout << "\nInvalid input. Try again.\n"
                 << endl;
        }
    }
}

void ItemShopMenu::buyMenu(Mythishop &shop, Player &shopper)
{
    int command; // user input to choose item and select amount or go back

    cout << "What do you wish to purchase?\n"
         << endl;

    // show stock of items.
    for (int i = 0; i < shop.getStock().size(); i++)
    {
        cout << i << ". " << shop.getItem(i)->getName() << endl;
    }

    cout << "\nPress -1 to go back\n"
         << endl;

    cin >> command;
    cout << endl;

    if (command == -1)
    { // user return to main shop menu
        return;
    }
    else if (command >= 0 && command < shop.getStock().size())
    {               // user selects an item
        int amount; // user selects amount of items to buy
        cout << "How many?" << endl;
        cin >> amount;

        if (shopper.getCoins() >= shop.getItem(command)->getPrice() * amount)
        {                                                                    // check if user has enough coins
            shopper.removeCoins(shop.getItem(command)->getPrice() * amount); // Takes coins from player

            for (int i = 0; i < shopper.getInventory().size(); i++)
            { // searches for the item in the inventory
                if (shopper.getInventory()[i]->getName() == shop.getItem(command)->getName())
                {                                                                                              // If it found the item
                    shopper.getInventory()[i]->setQuantity(shopper.getInventory()[i]->getQuantity() + amount); // Add the amount to the quantity
                }
            }
        }
        else
        {
            cout << "Not enough coins.\n"
                 << endl; // User does not have enough coins
        }
    }
    else
    {
        cerr << "Invalid input.\n"
             << endl; // User did not enter a valid input.
    }
}

void ItemShopMenu::sellMenu(Player &shopper)
{
    int command; // user input to choose item and select amount or go back

    cout << "What would you like to sell?\n"
         << endl;

    // show stock of items.
    for (int i = 0; i < shopper.getInventory().size(); i++)
    {
        cout << i << ". " << shopper.getInventory().at(i)->getName() << endl;
    }

    cout << "\nPress -1 to go back\n"
         << endl;

    cin >> command;
    cout << endl;

    if (command == -1)
    { // user return to main shop menu
        return;
    }
    else if (command >= 0 && command < shopper.getInventory().size())
    {               // user selects an item
        int amount; // user selects amount of items to sell
        cout << "How many?" << endl;
        cin >> amount;

        if (shopper.getInventory().at(command)->getQuantity() >= amount)
        {                                                                                  // check if user has enough items to sell
            shopper.addCoins(shopper.getInventory().at(command)->getPrice() / 2 * amount); // Takes coins from player

            shopper.getInventory().at(command)->setQuantity(shopper.getInventory().at(command)->getQuantity() - amount); // subtract the amount to the quantity
        }
        else
        {
            cout << "Not enough items.\n"
                 << endl; // User does not have enough items
        }
    }
    else
    {
        cerr << "Invalid input.\n"
             << endl; // User did not enter a valid input.
    }
}
