#include "../header/ItemShopMenu.h"

void ItemShopMenu::printMenu()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Welcome to the Mythishop! What service are you looking for?\n\n"
         << endl;
    cout << "1. Buy" << endl;
    cout << "2. Sell" << endl;
    cout << "3. Leave\n"
         << endl;

    int command;

    while (true)
    {
        cin >> command;
        cout << endl;

        if (command == 1)
        {
            buyMenu(*shop, shopper);
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
            cout << "1. Buy" << endl;
            cout << "2. Sell" << endl;
            cout << "3. Leave\n"
                 << endl;
        }
        cin.clear();
        cin.ignore();
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
        cout << i << ". " << shop.getItem(i)->getName() << "[$" << shop.getItem(i)->getPrice() << "]" << endl;
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

            for (int i = 0; i < shopper.getItemInventory().size(); i++)
            { // searches for the item in the item inventory
                if (shopper.getItemInventory()[i]->getName() == shop.getItem(command)->getName())
                {                                                                                              // If it found the item
                    shopper.getItemInventory()[i]->setQuantity(shopper.getItemInventory()[i]->getQuantity() + amount); // Add the amount to the quantity
                }
            }

            for (int i = 0; i < shopper.getBattleInventory().size(); i++)
            { // searches for the item in the battleItem inventory
                if (shopper.getBattleInventory()[i]->getName() == shop.getItem(command)->getName())
                {                                                                                              // If it found the item
                    shopper.getBattleInventory()[i]->setQuantity(shopper.getBattleInventory()[i]->getQuantity() + amount); // Add the amount to the quantity
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
    // Clear cin buffer
    cin.clear();
    cin.ignore();
}

void ItemShopMenu::sellMenu(Player &shopper)
{
    int command; // user input to choose item and select amount or go back

    cout << "What would you like to sell?\n"
         << endl;

    int indexNumber = 0; // consistent numbering for all items

    // show stock of items in Item Inventory.
    for (int i = 0; i < shopper.getItemInventory().size(); i++)
    {
        cout << i << ". " << shopper.getItemInventory().at(i)->getName() << "[$" << shopper.getItemInventory().at(i)->getPrice()  << "]" << endl;

        indexNumber = i;
    }

    indexNumber++; // increment indexNumber to start from the last index of the previous loop

    // continue to show stock of items in battle Inventory.
    for (int i = 0; i < shopper.getBattleInventory().size(); i++)
    {
        cout << indexNumber << ". " << shopper.getBattleInventory().at(i)->getName() << "[$" << shopper.getBattleInventory().at(i)->getPrice()  << "]" << endl;
        indexNumber++;
    }

    cout << "\nPress -1 to go back\n"
         << endl;

    cin >> command;
    cout << endl;

    if (command == -1)
    { // user return to main shop menu
        return;
    }
    else if (command >= 0 && command < shopper.getItemInventory().size() + shopper.getBattleInventory().size())
    {               // user selects an item
        int amount; // user selects amount of items to sell
        cout << "How many?" << endl;
        cin >> amount;

        if (command > shopper.getItemInventory().size() && shopper.getItemInventory().at(command)->getQuantity() >= amount)
        {                                                                                  // check if user has enough items to sell
            shopper.addCoins(shopper.getItemInventory().at(command)->getPrice() / 2 * amount); // Give coins to player

            shopper.getItemInventory().at(command)->setQuantity(shopper.getItemInventory().at(command)->getQuantity() - amount); // subtract the amount to the quantity
        }
        else if(shopper.getBattleInventory().at(command)->getQuantity() >= amount){
            shopper.addCoins(shopper.getBattleInventory().at(command)->getPrice() / 2 * amount); // Give coins to player

            shopper.getBattleInventory().at(command)->setQuantity(shopper.getBattleInventory().at(command)->getQuantity() - amount); // subtract the amount to the quantity
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
    // Clear cin buffer
    cin.clear();
    cin.ignore();
}
